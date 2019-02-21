#pragma once

#include "PropellerEngine.h"
#include "predefs.h"
#include "FuelTank.h"
#include "AGameRules/AGameRules.h"
#include "Kismet/GameplayStatics.h"

//default constructor
PropellerEngine::PropellerEngine() {
	//m_pEngineSoundComponent = CreateDefaultSubobject<UAudioComponent>("Engine Sound Component");

	//if (m_pEngineSound) m_pEngineSoundComponent->SetSound(m_pEngineSound);
}
//play sound depending on what gear the engine is in
void PropellerEngine::playEngineSound() {
	//UGameplayStatics::PlaySoundAtLocation()

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
void PropellerEngine::think() {

	lerp totalThrottle = m_lMainThrottle + m_lRudderThrottle;
	if (totalThrottle > 1) {
		totalThrottle = 1;
	}
	uint16 wishRPM = totalThrottle * 3000;

	float fuelToConsume = 0.01f * m_pFuelTank->getFuelDensity();

	//checks if there is enough fuel to consume and if so, consumes it
	if (m_pFuelTank->canConsumeFuel(fuelToConsume)) {
		
		m_pFuelTank->consumeFuel(fuelToConsume);

		float energy = fuelToConsume;
		float energyMain = energy * m_lMainThrottle / (m_lMainThrottle + m_lRudderThrottle);
		float energyRudder = energy - energyMain;

		m_rudderPropeller.addEnergy(energyRudder); //add energy to the rudder propeller
		m_mainPropeller.addEnergy(energyMain); //add energy to the main propeller
	}
}

