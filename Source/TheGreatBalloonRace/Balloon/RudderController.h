#pragma once

#include "CoreMinimal.h"
#include "VRBase/ABaseEntity/ABaseEntity.h"
#include "VRBase/AMoveLinear/AMoveLinear.h"
#include "RudderController.generated.h"


/**
 * 
 */
UCLASS()
class THEGREATBALLOONRACE_API ARudderController : public ABaseMoving
{
	GENERATED_BODY()
//public member functions
public:
	ARudderController();
	void think(ABaseController* pController);

//public member variables
public:
	ABaseController* pController;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ARudderController")
		UStaticMeshComponent* m_rudderController;
	
};