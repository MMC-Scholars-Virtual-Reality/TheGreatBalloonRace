// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AMoveLinear/AMoveLinear.h"
#include "PropellerController.generated.h"

class PropellerEngine;

/**
 * 
 */
UCLASS()
class THEGREATBALLOONRACE_API APropellerController : public AMoveLinear
{
	GENERATED_BODY()
public:
	APropellerController();

	void DefaultThink() override;

	PropellerEngine* m_pPropellerEngine;
	
	
};