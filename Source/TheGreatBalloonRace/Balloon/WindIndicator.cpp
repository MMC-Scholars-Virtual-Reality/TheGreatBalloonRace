#include "WindIndicator.h"
#include "WindField.h"
#include "ForceAccumulator.h"
#include "Components/ArrowComponent.h"
ENGINE_ArrowComponent_generated_h;

//WiNDICATOR
AWindIndicator::AWindIndicator() {
	m_pWindArrow = CreateDefaultSubobject<UArrowComponent>("WindArroww");
	m_pWindArrow->SetVisibility(true);
}

void AWindIndicator::DefaultThink() {
	meters m = GetActorLocation().Z;
	FVector WindDirection;
	WindDirection = WindField::GetWindDirectionAtAltitude(m);
	m_pWindArrow->SetWorldRotation(WindDirection.Rotation());
}