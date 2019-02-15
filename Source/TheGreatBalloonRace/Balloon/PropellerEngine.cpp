#pragma once

#include "PropellerEngine.h"
#include "predefs.h"
#include "FuelTank.h"

void PropellerEngine::playEngineSound() {


}
void PropellerEngine::setThrottle(lerp _flThrottle, EThrottle eThrottle) {
	lerp* plerpToSet = eThrottle == THROTTLE_MAIN ? &m_lMainThrottle : &m_lRudderThrottle;
	*plerpToSet = _flThrottle;
}
void PropellerEngine::checkGearChange(uint8 m_iCurrentGear) {


}
uint16 PropellerEngine::getGearIndepRPM() {
	uint16 RPMRange = (m_iRPM - (500 * (m_iCurrentGear - 1)));
	return RPMperGear * (m_iCurrentGear - 1) + RPMRange;
}
//does the opposite of the getGearIndepRPM function
void PropellerEngine::setByGearIndepRPM(uint16 indepRPM) {
	//uint16 newRPM = indepRPM - (500 * (m_iCurrentGear - 1));

}

void PropellerEngine::think(){

	lerp totalThrottle = m_lMainThrottle + m_lRudderThrottle;
	if (totalThrottle > 1) {
		totalThrottle = 1;
	}
	uint16 wishRPM = totalThrottle * 3000;
	
	float fuelToConsume = 0.01f * m_pFuelTank->getFuelDensity();

	if (m_pFuelTank->canConsumeFuel(fuelToConsume)){

	}
}

void PropellerEngine::setRPM(uint16 RPM) {
	m_iRPM = RPM;
}
void PropellerEngine::setGear(uint8 gear) {
	m_iCurrentGear = gear;
}