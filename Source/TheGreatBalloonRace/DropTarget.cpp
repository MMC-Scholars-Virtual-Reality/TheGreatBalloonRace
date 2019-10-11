// Fill out your copyright notice in the Description page of Project Settings.

#include "DropTarget.h"
#define TARGET_HORIZONTAL_THRESH 1024
#define TARGET_VERTICAL_THRESH 256

ADropTarget::ADropTarget() {
	// set default mesh
	staticMesh = NULL;

	// static mesh component
	m_pDropTargetMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Static Mesh Component");
	m_pDropTargetMeshComponent->SetStaticMesh(staticMesh);

	// set default material
	material0 = m_pDropTargetMeshComponent->GetMaterial(0);

	// set root component
	RootComponent = m_pDropTargetMeshComponent;

	// enable overlap
	m_pDropTargetMeshComponent->bGenerateOverlapEvents = true;

	m_pDropTargetMeshComponent->OnComponentBeginOverlap.AddDynamic(this, &ADropTarget::OnOverlapBegin);
	m_pDropTargetMeshComponent->OnComponentEndOverlap.AddDynamic(this, &ADropTarget::OnOverlapEnd);
	
}

void ADropTarget::PreInit() {
	Super::PreInit();
//	Msg("preinit");
	SetThink(&ADropTarget::ScoreThink);
}

bool ADropTarget::isOverlapping(APickup* pPickup) {
	m_pickupLoc = pPickup->GetActorLocation();
	m_targetLoc = GetActorLocation();
	m_targetLoc.Z = m_pickupLoc.Z = 0;

	bool result = ((m_targetLoc - m_pickupLoc).Size() < TARGET_HORIZONTAL_THRESH
		&& fabsf(GetActorLocation().Z - pPickup->GetActorLocation().Z) < TARGET_VERTICAL_THRESH);

	return result;
}

int ADropTarget::calculateScore(APickup* pPickup) {
//	Msg(__FUNCTION__);
	int points = 0;
	if ((m_pickupLoc - m_targetLoc).Size() < 20) {
		points += 3;
	}
	else if ((m_pickupLoc - m_targetLoc).Size() < 40) {
		points += 2;
	}
	else {
		points += 1;
	}

	return points;
}

void ADropTarget::ScoreThink(ADropTarget* vpDropTarget) {
	ADropTarget* pDropTarget = ExtractArg<ADropTarget>(vpDropTarget);
	// Loop through each pickup in m_pPickupList
	bool pickupOverlap = false;
	int i = 0;
	while (!pickupOverlap) { // Add condition
		pickupOverlap = pDropTarget->isOverlapping(pDropTarget->m_aPickupList[i]);
		if (pickupOverlap) { // If there is a pickup overlap,
			pDropTarget->calculateScore(pDropTarget->m_aPickupList[i]); //Calculate score
			pDropTarget->m_aPickupList.RemoveAt(i); // Remove the pickup from list
		}
		i++;
	}
}


void ADropTarget::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
//	Msg(__FUNCTION__);
}

void ADropTarget::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
//	Msg(__FUNCTION__);
}

