#include "WindIndicator.h"
#include "WindField.h"
#include "ForceAccumulator.h"
#include "Components/ArrowComponent.h"

//WiNDICATOR
void AWindIndicator::DefaultThink() {
	meters m = 0;
	FVector WindDirection = WindField::GetWindDirectionAtAltitude(m);
	

}


