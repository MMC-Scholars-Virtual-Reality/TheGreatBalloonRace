#pragma once

#include "CoreMinimal.h"
#include "VRBase/ABaseEntity/ABaseEntity.h"
#include "WindIndicator.generated.h"

/**
 * 
 */
UCLASS()
class THEGREATBALLOONRACE_API AWindIndicator : public ABaseEntity
{
	GENERATED_BODY()
	
public:
	virtual void DefaultThink() override;

	
	
};
