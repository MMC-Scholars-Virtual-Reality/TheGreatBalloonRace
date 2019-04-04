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
	Msg("preinit");
}

bool ADropTarget::isOverlapping(APickup* pPickup) {
	FVector pickupLoc = pPickup->GetActorLocation();
	FVector targetLoc = GetActorLocation();
	targetLoc.Z = pickupLoc.Z = 0;

	bool result = ((targetLoc - pickupLoc).Size() < TARGET_HORIZONTAL_THRESH
		&& fabsf(GetActorLocation().Z - pPickup->GetActorLocation().Z) < TARGET_VERTICAL_THRESH);

	return result;
}

void ADropTarget::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
		Msg(__FUNCTION__);
}

void ADropTarget::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
	Msg(__FUNCTION__);
}

