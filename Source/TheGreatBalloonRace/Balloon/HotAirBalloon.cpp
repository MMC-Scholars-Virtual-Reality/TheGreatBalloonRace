
#include "HotAirBalloon.h"
#include "System/NLogger.h"
//set pointers in other classes to these objects
AHotAirBalloon::AHotAirBalloon() {
	m_BalloonMesh = CreateDefaultSubobject<UStaticMeshComponent>("m_BalloonMesh");
	m_pBurnerController = CreateDefaultSubobject<ABurnerController>("m_pBurnerController");
	
	m_ForceAccumulator.m_pBalloon = this;
}

void AHotAirBalloon::PreInit() {
	//FVector loc = GetActorLocation();
	//m_pBurnerController = (ABurnerController*) g_pWorld->SpawnActor(ABurnerController::StaticClass(), &loc);
	m_velocity = FVector::ZeroVector;
}

void AHotAirBalloon::PostInit() {

}

//models the movement in response to forces
void AHotAirBalloon::DefaultThink() {
	m_ForceAccumulator.Think();

	FVector acceleration = m_ForceAccumulator.getSummedForces() / GetMass();
	Msg(acceleration);
	MoveThink(acceleration);
}

kilos AHotAirBalloon::GetMass() {
	return 1000;
}

void AHotAirBalloon::MoveThink(FVector acceleration) {
	//if we have a weird frametime, don't do anything
	if (fabsf(g_pGlobals->frametime) > 0.2f)
		return;

	//calculate change in velocity
	FVector dv = acceleration * g_pGlobals->frametime;
	m_velocity += dv;

	//calculate change in position
	FVector dp = m_velocity * g_pGlobals->frametime;
	AddActorLocalOffset(dp);
}


