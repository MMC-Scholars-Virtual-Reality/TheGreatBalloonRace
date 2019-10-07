// This software is under partial ownership by The Ohio State University, for it is a product of student employees. For official policy, see https://tco.osu.edu/sites/default/files/pdfs/IP-Policy.pdf or contact The Ohio State University Office of Legal Affairs.

#pragma once

#include "CoreMinimal.h"
#include "VRBase/ABaseEntity/ABaseEntity.h"
#include "Components/SplineComponent.h"
#include "Components/SplineMeshComponent.h"
#include "System/NLogger.h"
#include "PathCreator.generated.h"

UCLASS()
class THEGREATBALLOONRACE_API APathCreator : public ABaseEntity {
	GENERATED_BODY()

	public:
		APathCreator();
		virtual void OnConstruction(const FTransform& Transform) override;

		USplineComponent* m_pSpline;

		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spline", DisplayName = "Mesh")
		UStaticMesh* m_pSplineMesh;

		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spline", DisplayName = "Mesh Forward Dir")
		TEnumAsByte<ESplineMeshAxis::Type> m_pSplineForward;
};