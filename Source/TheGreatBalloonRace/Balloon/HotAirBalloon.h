#pragma once

#include "CoreMinimal.h"
#include "VRBase/ABaseEntity/ABaseEntity.h"
#include "PropellerEngine.h"
#include "FuelTank.h"
#include "ForceAccumulator.h"
#include "Burner.h"
#include "Propeller.h"
#include "BurnerController.h"
#include "PropellerController.h"
#include "RudderController.h"
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

	kilos GetMass();

	//public member variables
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Static Mesh")
		UStaticMeshComponent* m_BalloonMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Physics Parameters")
		float m_flStartingBalloonTemperature;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Physics Parameters")
		float m_flStartingBalloonEnergy;




	//private member variables
private:
	ForceAccumulator m_ForceAccumulator;

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
		ABurnerController* m_pBurnerController;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
		APropellerController* m_pPropellerController;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
		ARudderController* m_pRudderController;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Physics Parameters")
		ABaseEntity* m_pRudderDirection;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Physics Parameters")
		ABaseEntity* m_pPropellerDirection;
	
private:
	//Movement
	FVector m_velocity;
	void MoveThink(FVector acceleration);

public:
	FVector GetVelocity() const override { return m_velocity; }
};
