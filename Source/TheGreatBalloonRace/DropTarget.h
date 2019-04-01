// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VRBASE/System/predefs.h"
#include "VRBase/ABaseEntity/ABaseEntity.h"
#include "VRBase/APickup/APickup.h"
#include "Components/StaticMeshComponent.h"
#include "DropTarget.generated.h"

/**
 * 
 */
UCLASS()
class THEGREATBALLOONRACE_API ADropTarget : public ABaseEntity
{
	GENERATED_BODY()
	
public:

	ADropTarget();
	void PreInit() override;

	// Components
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Target")
		UStaticMeshComponent*	m_pPickupMeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Target Static Mesh")
		UStaticMesh*			staticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Target Material")
		UMaterialInterface*		material0;

	// declare overlap begin function
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// declare overlap end function
	UFUNCTION()
		void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
	FVector m_centerLoc;
	APickup* m_pPickup;
};
