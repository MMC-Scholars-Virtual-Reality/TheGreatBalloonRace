#pragma once

#include "PropellerEngine.h"
#include "predefs.h"
#include "FuelTank.h"
#include "ForceAccumulator.h"
#include "AGameRules/AGameRules.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"


//default constructor
PropellerEngine::PropellerEngine() {
	m_pFuelTank = NULL;
	m_mainPropellerDirection = NULL;
	m_rudderPropellerDirection = NULL;
	m_pSoundLocation = NULL;
	m_pEngineSound = NULL;
}
//play sound depending on what gear the engine is in
void PropellerEngine::playEngineSound() {
	if (m_pSoundLocation && m_iRPM != 0)
	{
		if (m_iCurrentGear == 1) {
			UGameplayStatics::PlaySoundAtLocation(m_pEngineSound, m_pEngineSound, m_pSoundLocation->GetActorLocation());
		}
		else if (m_iCurrentGear == 2) {
			UGameplayStatics::PlaySoundAtLocation(m_pEngineSound, m_pEngineSound, m_pSoundLocation->GetActorLocation(), 1.5F, 1.5F);
		}
		else if (m_iCurrentGear == 3) {
			UGameplayStatics::PlaySoundAtLocation(m_pEngineSound, m_pEngineSound, m_pSoundLocation->GetActorLocation(), 2.0F, 2.0F);
		}
		else if (m_iCurrentGear == 4) {
			UGameplayStatics::PlaySoundAtLocation(m_pEngineSound, m_pEngineSound, m_pSoundLocation->GetActorLocation(), 2.5F, 2.5F);
		}
	}
}
//chooses which throttle to set and then sets it based on the inputted value
void PropellerEngine::setThrottle(lerp _flThrottle, EThrottle eThrottle) {
	lerp* plerpToSet = eThrottle == THROTTLE_MAIN ? &m_lMainThrottle : &m_lRudderThrottle;
	*plerpToSet = _flThrottle;
}

//returns linear value for current RPM and current Gear
uint16 PropellerEngine::getGearIndepRPM() {
	uint16 RPMRange = (m_iRPM - (500 * (m_iCurrentGear - 1)));
	return RPMperGear * (m_iCurrentGear - 1) + RPMRange;
}
//when given an indepRPM value from above, set the values of the current RPM and gear to
//correspond with the indepRPM linear value
void PropellerEngine::setByGearIndepRPM(uint16 indepRPM) {
	//uint16 newRPM = indepRPM - (500 * (m_iCurrentGear - 1));
	uint16 newGear = (indepRPM / RPMperGear) + 1;
	uint16 newRPM = indepRPM - ((newGear-1) * RPMperGear) + 500 * (newGear - 1);
	m_iRPM = newRPM;
	m_iCurrentGear = newGear;
}

//function that goes off every frame during the program
void PropellerEngine::think(ForceAccumulator* pAccumulator) {
	if (!m_mainPropellerDirection || !m_rudderPropellerDirection)
		return;


	m_mainPropeller.think();
	m_rudderPropeller.think();
	playEngineSound();
	lerp totalThrottle = m_lMainThrottle + m_lRudderThrottle;
	if (totalThrottle > 1) {
		totalThrottle = 1;
	}
	uint16 wishRPM = totalThrottle * 3000;
	float fuelToConsume = 0.01f * m_pFuelTank->getFuelDensity();

	//checks if there is enough fuel to consume and if so, consumes it
	if (m_pFuelTank->canConsumeFuel(fuelToConsume)) {
		//m_pFuelTank->consumeFuel(fuelToConsume);
		float energy = fuelToConsume * 100;
		float energyMain = energy * m_lMainThrottle / (m_lMainThrottle + m_lRudderThrottle);
		float energyRudder = energy - energyMain;
		m_rudderPropeller.addEnergy(energyRudder); //add energy to the rudder propeller
		m_mainPropeller.addEnergy(energyMain); //add energy to the main propeller
	}
	
	//ask each propeller how much thrust they are providing, get direction from m_mainPropellerDirection and m_rudderPropellerDirection
	newtons mainThrust = m_mainPropeller.getPropulsionStrength();
	newtons rudderThrust = m_rudderPropeller.getPropulsionStrength();
	FVector mainDirection = m_mainPropellerDirection->GetActorForwardVector();
	FVector rudderDirection = m_rudderPropellerDirection->GetActorForwardVector();
	//makes the magnitude of main and rudder direction to be equal to the thrust, then sends the force to the force accumulator
	mainDirection.Normalize();
	mainDirection *= mainThrust;
	rudderDirection.Normalize();
	rudderDirection *= rudderThrust;
	pAccumulator->addForce(Force{Force::PROPULSION, mainDirection});
}


