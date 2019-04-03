// Fill out your copyright notice in the Description page of Project Settings.

#include "DropTarget.h"

ADropTarget::ADropTarget() {
	// set default mesh
	// staticMesh = NULL;

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
	m_centerLoc = GetActorLocation();
	Msg("preinit");
}

void ADropTarget::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
		Msg("ITS A PICKUP! SOME POINT(S) ADDED");
}

void ADropTarget::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
	Msg(__FUNCTION__);
}

