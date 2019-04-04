
#include "HotAirBalloon.h"
#include "System/NLogger.h"
//set pointers in other classes to these objects
AHotAirBalloon::AHotAirBalloon() {
	m_BalloonMesh = CreateDefaultSubobject<UStaticMeshComponent>("m_BalloonMesh");
	m_pBurnerController = CreateDefaultSubobject<ABurnerController>("m_pBurnerController");
	m_pRudderController = CreateDefaultSubobject<ARudderController>("m_pRudderController");

	m_ForceAccumulator.m_pBalloon = this;
	m_pBurnerController->m_pBurner = &m_ForceAccumulator.m_burner;
	m_pRudderController->m_pEngine = &m_ForceAccumulator.m_propellerEngine;
}

void AHotAirBalloon::PreInit() {
	m_velocity = FVector::ZeroVector; //sets velocity to 0
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
	return 400 + m_ForceAccumulator.m_burner.GetAirMass();
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
}
