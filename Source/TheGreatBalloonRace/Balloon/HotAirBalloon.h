#pragma once

#include "CoreMinimal.h"
#include "VRBase/ABaseEntity/ABaseEntity.h"
#include "PropellerEngine.h"
#include "FuelTank.h"
#include "ForceAccumulator.h"
#include "Burner.h"
#include "Propeller.h"
#include "BurnerController.h"
#include "HotAirBalloon.generated.h"

/**
 * 
 */
UCLASS()
class THEGREATBALLOONRACE_API AHotAirBalloon : public ABaseEntity
{
	GENERATED_BODY()
	//public member functions
public:	
	AHotAirBalloon();
	void PreInit() override;
	void PostInit() override;
	void DefaultThink() override;



	//private member variables
private:
	PropellerEngine m_Engine;
	FuelTank m_FuelTank;
	//ForceAccumulator m_ForceAccumulator;
	/*Burner m_Burner;
	Propeller m_Propeller;
	BurnerController* m_pBurnerController;
	UStaticMeshComponent* m_BalloonMesh;
	*/
	//finish checking each object and adding default constructor if needed like in fueltank
};
