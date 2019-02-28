#include "Burner.h"
#include "Atmosphere.h"
#include "ForceAccumulator.h"
#include "FuelTank.h"
#include "VRBase/System/Globals.h"

Burner::AirVolume::AirVolume(const float _BalloonRadius, const float _currentEnergy, const float _temperature) {
	m_radius = _BalloonRadius;
	m_temperature = _temperature;
	m_currentEnergy = _currentEnergy;

	//Use half-sphere volume equation
	m_volume = (2.f / 3.f) * PI * powf(m_radius, 3);
}

void Burner::AirVolume::addEnergy(const joules heat) {
	m_currentEnergy += heat; //Adds heat to the current energy

	updateParametersFromEnergy(); //Update the temperature because energy was just increased
}

void Burner::AirVolume::transferHeatTo(meters area, meters altitude, AirVolume* pOtherVolume) {
	kelvin temp = pOtherVolume ? pOtherVolume->m_temperature : Atmosphere::getAirTemperatureAtAltitude(altitude);
	//If the other volume exists, pull the temperature from it, if not, pull the temperature from the atmosphere

	therm_cond average = (Atmosphere::getThermalConductivityOfAir(m_temperature) 
		+ Atmosphere::getThermalConductivityOfAir(temp)) / 2;
	//Calculate the average thermal conductivity from the air inside the balloon and the air outside the baloon

	joules heat = g_pGlobals->frametime * ((average * area * (m_temperature - temp)) / 0.01);
	//Using the heat conduction equation, calculate the amount of heat transferred across the volumes

	if (pOtherVolume) { //If the other volume exists, add energy to it
		pOtherVolume->addEnergy(heat);
	}
	m_currentEnergy -= heat; //Subtract energy from the calling volume since it was given to the other volume

	updateParametersFromEnergy(); //Update the temperature of the volume with heat being added
	if (pOtherVolume) { //If the other volume exists, update its temperature as well
		pOtherVolume->updateParametersFromEnergy();  
	}
}

void Burner::AirVolume::updateParametersFromTemperature() {

}

void Burner::AirVolume::updateParametersFromEnergy() {
	m_temperature = (((2.0 / 3.0) * m_currentEnergy) / BOLTZMANN_CONSTANT);
}  //Using the kinetic temperature equation, update the current temperature using current energy

void Burner::think() {
	//Using a square root function to model fuel efficiency, we find the amount of fuel to consume
	float fuelToConsume = sqrtf(m_throttle); 
	m_pFuelTank->consumeFuel(fuelToConsume); //Consume the fuel from the tank

	m_bottomState.addEnergy(m_throttle * 500 * m_pFuelTank->getFuelDensity()); //Add energy to the bottom state based on the throttle

	//Transfer heat from the bottom volume to the top volume
	//The area is a circle between the bottom and the top of the hot air balloon
	m_bottomState.transferHeatTo(PI * sqr(m_bottomState.getRadius()), m_pForceAccumulator->getAircraftAltitude(), &m_topState);

	//Transfer heat from the top volume to the outside atmosphere
	//The area is half of a sphere's surface area to model the balloon itself
	m_topState.transferHeatTo(2 * PI * sqr(m_topState.getRadius()), m_pForceAccumulator->getAircraftAltitude(), NULL);
}

void Burner::SetThrottleLevel(lerp _throttle) {
	m_throttle = _throttle; //Set the throttle level to the given amount
}

newtons Burner::GetBuoyantForce() {
	return (Atmosphere::getAirDensityAtAltitude(m_pForceAccumulator->getAircraftAltitude()) * gravity * m_topState.getVolume());
} //Using the buoyant force equation, calculate the buoyant force and return it