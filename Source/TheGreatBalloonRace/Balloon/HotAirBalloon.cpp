
#include "HotAirBalloon.h"
#include "System/NLogger.h"
AHotAirBalloon::AHotAirBalloon() {
	m_pBalloonMesh = CreateDefaultSubobject<UStaticMeshComponent>("m_BalloonMesh");
	RootComponent = m_pBalloonMesh;
	m_pBurnerController = CreateDefaultSubobject<ABurnerController>("m_pBurnerController");
	m_pRudderController = CreateDefaultSubobject<ARudderController>("m_pRudderController");

	m_ForceAccumulator.m_pBalloon = this;
	m_pBurnerController = NULL;
	m_pPropellerController = NULL;
	m_pRudderController = NULL;
	m_ForceAccumulator.m_propellerEngine.m_mainPropeller.m_pfAccum = &m_ForceAccumulator;
	m_ForceAccumulator.m_propellerEngine.m_rudderPropeller.m_pfAccum = &m_ForceAccumulator;

}

#define max(a,b) ((a)<(b)?(b):(a))
void AHotAirBalloon::PreInit() {
	m_velocity = FVector::ZeroVector; //sets velocity to 0
	m_ForceAccumulator.m_burner.SetTemperature(m_flStartingBalloonTemperature);
	//float startingEnergy = max(0.001f, m_flStartingBalloonEnergy);
	//m_ForceAccumulator.m_propellerEngine.m_mainPropeller.m_jCurrentEnergy = startingEnergy;
	
	if (m_pBurnerController)
		m_pBurnerController->m_pBurner = &m_ForceAccumulator.m_burner;
	if (m_pPropellerController)
		m_pPropellerController->m_pEngine = &m_ForceAccumulator.m_propellerEngine;
	if (m_pRudderController)
		m_pRudderController->m_pEngine = &m_ForceAccumulator.m_propellerEngine;
	
	
	m_ForceAccumulator.m_propellerEngine.m_mainPropellerDirection = m_pPropellerDirection;
	m_ForceAccumulator.m_propellerEngine.m_rudderPropellerDirection = m_pRudderDirection;
}

void AHotAirBalloon::PostInit() {

}

//models the movement in response to forces
void AHotAirBalloon::DefaultThink() {
	m_ForceAccumulator.Think();
	FVector acceleration = m_ForceAccumulator.getSummedForces() / GetMass();
	//Msg(acceleration);
	MoveThink(acceleration);
}

kilos AHotAirBalloon::GetMass() {
	return 100 + m_ForceAccumulator.m_burner.GetAirMass();
}

void AHotAirBalloon::MoveThink(FVector acceleration) {
	//if we have a weird frametime, don't do anything
	if (fabsf(g_pGlobals->frametime) > 0.2f)
		return;

	//calculate change in velocity
	FVector dv = acceleration * g_pGlobals->frametime;
	m_velocity += dv;

	//calculate change in position
	//our velocity is m/s, but Unreal world units are cm
	FVector dp = m_velocity * 100 * g_pGlobals->frametime;
	AddActorLocalOffset(dp);

	if (GetActorLocation().Z < 0) {
		FVector loc = GetActorLocation();
		loc.Z = 0;
		SetActorLocation(loc);
	}
}