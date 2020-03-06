
#include "HotAirBalloon.h"
#include "System/NLogger.h"

extern AHotAirBalloon* g_pHotAirBalloon = NULL;

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
	g_pHotAirBalloon = this;

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

// clamps a lerp value
lerp clamp(lerp min, lerp val, lerp max) {
	if (min < max) {
		if (val < min) val = min;
		if (val > max) val = max;
	}
	else { // max < min
		if (val < max) val = max;
		if (val > min) val = min;
	}
	return val;
}

//models the movement in response to forces
void AHotAirBalloon::DefaultThink() {
	if (m_pRudderController) {
		// convert lerp to a [-1, 1] value
		lerp lRotation = (clamp(0, m_pRudderController->GetLerpPosition(), 1) - 0.5) * 2;

		// convert lerp to rotation (up = left, down = right)
		FRotator rRotation = FRotator(0, -180 * lRotation, 0);
		SetActorRotation(rRotation);
	}

	m_ForceAccumulator.Think();
	FVector acceleration = m_ForceAccumulator.getSummedForces() / GetMass();
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
	AddActorWorldOffset(dp, true); // sweep must be true for collision

	// balloon cannot fall below the ground
	if (GetActorLocation().Z < 0) {
		FVector loc = GetActorLocation();
		loc.Z = 0;
		SetActorLocation(loc);
	}
}