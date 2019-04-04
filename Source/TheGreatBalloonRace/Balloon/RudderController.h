#pragma once

#include "CoreMinimal.h"
#include "VRBase/ABaseEntity/ABaseEntity.h"
#include "VRBase/AMoveLinear/AMoveLinear.h"
#include "PropellerEngine.h"
#include "predefs.h"
#include "RudderController.generated.h"



/**
 * 
 */
UCLASS()
class THEGREATBALLOONRACE_API ARudderController : public AMoveLinear
{
	GENERATED_BODY()
//public member functions
public:
	ARudderController();
	void DefaultThink() override;

//public member variables
public:
	PropellerEngine* m_pEngine; 

};