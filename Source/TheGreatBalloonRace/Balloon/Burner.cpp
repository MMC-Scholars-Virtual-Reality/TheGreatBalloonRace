#include "Burner.h"
#include "Atmosphere.h"
#include "ForceAccumulator.h"
#include "FuelTank.h"
#include "VRBase/System/Globals.h"



Burner::Burner(const float _BalloonRadius, const float _temperature) {
	m_Temperature = _temperature;
	m_Volume = (4 / 3) * PI * sqr(_BalloonRadius) * _BalloonRadius;
}

void Burner::think() {
	//Using a square root function to model fuel efficiency, we find the amount of fuel to consume
	float fuelToConsume = sqrtf(m_throttle); 
	m_pFuelTank->consumeFuel(fuelToConsume); //Consume the fuel from the tank

	

	kelvin dt = m_Temperature - Atmosphere::getAirTemperatureAtAltitude(m_pForceAccumulator->getAircraftAltitude());
	float time = min(g_pGlobals->frametime, 0.05f);
	m_Temperature -= time * dt / 400;

	//add temperature based on our throttel level
	//Msg("Adding %f", m_throttle * time);
	m_Temperature += m_throttle * time;

	m_pForceAccumulator->addForce(Force{ Force::BUOYANCY, FVector(0,0,GetBuoyantForce()) });
}

void Burner::SetThrottleLevel(lerp _throttle) {
	m_throttle = _throttle; //Set the throttle level to the given amount
}

newtons Burner::GetBuoyantForce() {
	return (Atmosphere::getAirDensityAtAltitude(m_pForceAccumulator->getAircraftAltitude()) * gravity * m_Volume);
} //Using the buoyant force equation, calculate the buoyant force and return it

kilos Burner::GetAirMass() const {
	density dens = GetDensity();
	return dens * m_Volume;
}

density Burner::GetDensity() const {
	return Atmosphere::getAirDensityAtAltitude(m_pForceAccumulator->getAircraftAltitude()) - (m_Temperature - 273) / 1000;
}