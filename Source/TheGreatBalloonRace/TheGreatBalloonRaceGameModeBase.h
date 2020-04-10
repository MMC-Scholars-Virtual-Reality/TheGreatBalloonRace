// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PathRing.h"
#include "TheGreatBalloonRaceGameModeBase.generated.h"


#define g_iTimePerRing 10

/**
 * 
 */
UCLASS()
class THEGREATBALLOONRACE_API ATheGreatBalloonRaceGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	public:

		TArray<APathRing*> m_aPathRings;
		int m_iTimeLimit;

		UFUNCTION(BlueprintCallable)
		void EndGame(bool playerWon);
	
};
