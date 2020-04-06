// This software is under partial ownership by The Ohio State University, for it is a product of student employees. For official policy, see https://tco.osu.edu/sites/default/files/pdfs/IP-Policy.pdf or contact The Ohio State University Office of Legal Affairs.

#include "PathRing.h"
#include "ABasePawn/ABasePawn.h"
#include "System/NLogger.h"
#include "TheGreatBalloonRaceGameModeBase.h"

#define RING_MESH "StaticMesh'/Game/Models/Ring.Ring'"

APathRing::APathRing() {
	m_pMesh = FindMesh(RING_MESH);

	m_pMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("mesh component");
	RootComponent = m_pMeshComponent;

	m_pMeshComponent->SetStaticMesh(m_pMesh);
	vec scale = 1.2;
	m_pMeshComponent->SetWorldScale3D(FVector(scale, scale, scale));
	m_pMeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);

	m_bCollisionBox = CreateDefaultSubobject<UBoxComponent>("collision box");
	m_bCollisionBox->SetupAttachment(RootComponent);

	FVector min, max;
	m_pMeshComponent->GetLocalBounds(min, max);
	m_bCollisionBox->SetBoxExtent((max - min) / 2);
	m_bCollisionBox->bGenerateOverlapEvents = true;
	m_bCollisionBox->OnComponentBeginOverlap.AddDynamic(this, &APathRing::OnOverlapBegin);
	m_bCollisionBox->OnComponentEndOverlap.AddDynamic(this, &APathRing::OnOverlapEnd);
}

void APathRing::PreInit() {
	ATheGreatBalloonRaceGameModeBase* gameMode = GetWorld()->GetAuthGameMode<ATheGreatBalloonRaceGameModeBase>();
	if(gameMode) gameMode->m_aPathRings.Push(this);
}

void APathRing::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr)) {
		ABasePawn* pawn = Cast<ABasePawn>(OtherActor);
		if (pawn) {
			ATheGreatBalloonRaceGameModeBase* gameMode = GetWorld()->GetAuthGameMode<ATheGreatBalloonRaceGameModeBase>();
			Msg("ring overlap with pawn");
			if (gameMode->m_aPathRings.Num() == 1) {
				gameMode->EndGame(true);
			}
			
			gameMode->m_aPathRings.Remove(this);
			this->DestroyEntity();
		}
	}
}

void APathRing::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

