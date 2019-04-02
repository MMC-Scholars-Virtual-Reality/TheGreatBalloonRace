
#include "HotAirBalloon.h"
#include "System/NLogger.h"
//set pointers in other classes to these objects
AHotAirBalloon::AHotAirBalloon() {
	m_BalloonMesh = CreateDefaultSubobject<UStaticMeshComponent>("m_BalloonMesh");
	m_pBurnerController = CreateDefaultSubobject<ABurnerController>("m_pBurnerController");
	
}

void AHotAirBalloon::PreInit() {
	//FVector loc = GetActorLocation();
	//m_pBurnerController = (ABurnerController*) g_pWorld->SpawnActor(ABurnerController::StaticClass(), &loc);
	
}

void AHotAirBalloon::PostInit() {

}

//models the movement in response to forces
void AHotAirBalloon::DefaultThink() {
	m_ForceAccumulator.Think();
	Msg(m_ForceAccumulator.getSummedForces());
	
}


