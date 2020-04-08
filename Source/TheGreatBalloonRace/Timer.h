// This software is under partial ownership by The Ohio State University, for it is a product of student employees. For official policy, see https://tco.osu.edu/sites/default/files/pdfs/IP-Policy.pdf or contact The Ohio State University Office of Legal Affairs.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TheGreatBalloonRaceGameModeBase.h"
#include "Timer.generated.h"

/**
 * 
 */
UCLASS()
class THEGREATBALLOONRACE_API UTimer : public UUserWidget
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable)
	FString SecondsToMSS(int seconds);

	UWorld* m_pGameWorld;
	ATheGreatBalloonRaceGameModeBase* m_pGameMode;
	int m_iTimeLimit = 75;

public:

	UFUNCTION(BlueprintCallable)
	FString GetText();
};
