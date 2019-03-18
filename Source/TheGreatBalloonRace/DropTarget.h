// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VRBase/ABaseEntity/ABaseEntity.h"
#include "Components/StaticMeshComponent.h"
#include "DropTarget.generated.h"

/**
 * 
 */
UCLASS()
class VRBASE_API ADropTarget : public ABaseEntity
{
	GENERATED_BODY()
	
public:

	ADropTarget();

	

		UStaticMeshComponent*	m_pPickupMeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Pickup Static Mesh")
		UStaticMesh*			staticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Pickup Materials")
		UMaterialInterface*		material0;
	
	

};
