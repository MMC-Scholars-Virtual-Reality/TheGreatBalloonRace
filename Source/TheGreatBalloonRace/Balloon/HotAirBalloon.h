#pragma once

#include "CoreMinimal.h"
#include "VRBase/ABaseEntity/ABaseEntity.h"
#include "PropellerEngine.h"
#include "FuelTank.h"
#include "ForceAccumulator.h"
#include "Burner.h"
#include "Propeller.h"
#include "BurnerController.h"
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
		float m_flStartingBalloonEnergy;

	//private member variables
private:
	ForceAccumulator m_ForceAccumulator;
	ABurnerController* m_pBurnerController;
	ARudderController* m_pRudderController;
	
	//Movement
	FVector m_velocity;
	void MoveThink(FVector acceleration);

public:
	FVector GetVelocity() const override { return m_velocity; }
};