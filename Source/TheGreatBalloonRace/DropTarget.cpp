// Fill out your copyright notice in the Description page of Project Settings.

#include "DropTarget.h"

ADropTarget::ADropTarget() {
	// set default mesh
	staticMesh = NULL;

	// static mesh component
	m_pPickupMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Static Mesh Component");
	m_pPickupMeshComponent->SetStaticMesh(staticMesh);

	// set default material
	material0 = m_pPickupMeshComponent->GetMaterial(0);

	// set root component
	RootComponent = m_pPickupMeshComponent;

	// enable overlap
	m_pPickupMeshComponent->bGenerateOverlapEvents = true;
}

void ADropTarget::PreInit() {
	Super::PreInit();
	m_centerLoc = GetActorLocation();
}

void ADropTarget::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	m_pPickup = dynamic_cast<APickup*>(OtherActor);
	if (m_pPickup) {
		Msg("ITS A PICKUP! SOME POINT(S) ADDED");
	}
}

void ADropTarget::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
	Msg(__FUNCTION__);
}

