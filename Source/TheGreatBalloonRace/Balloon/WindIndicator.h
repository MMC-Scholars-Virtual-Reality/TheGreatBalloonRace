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
	//public member functions
public:
	AWindIndicator();
	virtual void DefaultThink() override;

	//private member variables
private:
	class UArrowComponent* m_pWindArrow;

	
	
};
