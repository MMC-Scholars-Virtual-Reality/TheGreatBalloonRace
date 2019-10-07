// This software is under partial ownership by The Ohio State University, for it is a product of student employees. For official policy, see https://tco.osu.edu/sites/default/files/pdfs/IP-Policy.pdf or contact The Ohio State University Office of Legal Affairs.

#pragma once

#include "CoreMinimal.h"
#include "VRBase/ABaseEntity/ABaseEntity.h"
#include "Components/SplineComponent.h"
#include "PathCreator.generated.h"

UCLASS()
class THEGREATBALLOONRACE_API APathCreator : public ABaseEntity {
	GENERATED_BODY()
	
	public:
		APathCreator();

		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spline", DisplayName = "Spline")
		USplineComponent* m_pSpline;
};
