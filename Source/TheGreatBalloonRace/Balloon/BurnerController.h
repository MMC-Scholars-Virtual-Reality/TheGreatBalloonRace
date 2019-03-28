#pragma once

#include "CoreMinimal.h"
#include "VRBase/AMoveLinear/AMoveLinear.h"
#include "Burner.h"
#include "BurnerController.generated.h"

/**
 * 
 */
UCLASS()
class THEGREATBALLOONRACE_API ABurnerController : public AMoveLinear
{
	GENERATED_BODY()
	//public member functions
public:
	ABurnerController();
	void DefaultThink();

	//public member variables
public:
	Burner* m_pBurner;
};
