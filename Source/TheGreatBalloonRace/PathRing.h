// This software is under partial ownership by The Ohio State University, for it is a product of student employees. For official policy, see https://tco.osu.edu/sites/default/files/pdfs/IP-Policy.pdf or contact The Ohio State University Office of Legal Affairs.

#pragma once

#include "CoreMinimal.h"
#include "VRBase/ABaseEntity/ABaseEntity.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "PathRing.generated.h"

UCLASS()
class THEGREATBALLOONRACE_API APathRing : public ABaseEntity {
	GENERATED_BODY()
	
	public:
		APathRing();

		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Mesh", DisplayName = "Mesh")
		UStaticMesh* m_pMesh;

		UStaticMeshComponent* m_pMeshComponent;

		UBoxComponent* m_bCollisionBox;

		UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
		UFUNCTION()
		void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
