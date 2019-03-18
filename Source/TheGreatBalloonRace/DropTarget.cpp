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

