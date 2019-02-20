#pragma once

#include "PropellerEngine.h"
#include "predefs.h"
#include "FuelTank.h"

PropellerEngine::PropellerEngine() {
	//m_pEngineSoundComponent = CreateDefaultSubobject<UAudioComponent>("Engine Sound Component");

	//if (m_pEngineSound) m_pEngineSoundComponent->SetSound(m_pEngineSound);
}

void PropellerEngine::playEngineSound() {


}
//chooses which throttle to set and then sets it based on the inputted value
void PropellerEngine::setThrottle(lerp _flThrottle, EThrottle eThrottle) {
	lerp* plerpToSet = eThrottle == THROTTLE_MAIN ? &m_lMainThrottle : &m_lRudderThrottle;
	*plerpToSet = _flThrottle;
}
void PropellerEngine::checkGearChange(uint8 m_iCurrentGear) {


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
	uint16 newRPM = indepRPM - RPMperGear * (m_iCurrentGear - 1);
	uint16 newGear = indepRPM / m_iRPM;
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


	//checks if there is enough fuel to consume and if so, consumes it
	/*if (m_pFuelTank->canConsumeFuel(m_fFuelToConsume)) {
		m_pFuelTank->consumeFuel(m_fFuelToConsume);
		m_mainPropeller->addEnergy(getWork(m_fFuelToConsume)); //add energy to the main propeller, 
	}*/
}
//finds the amount of work performed by the amount of fuel consumed
joules PropellerEngine::getWork(float m_fFuelToConsume){
	//.5 * moment of inertia * angular velocity^2
	//joules work = .5 * m_mainPropeller.m_nInertia * sqr(m_mainPropeller.m_dRotationalVelo);
	//return work;
	return 0;
}
void PropellerEngine::setRPM(uint16 RPM) {
	m_iRPM = RPM;
}
void PropellerEngine::setGear(uint8 gear) {
	m_iCurrentGear = gear;
}