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
	m_currentEnergy += heat;
}

void Burner::AirVolume::transferHeatTo(meters area, meters altitude, AirVolume* pOtherVolume) {
	kelvin temp = pOtherVolume ? pOtherVolume->m_temperature : Atmosphere::getAirTemperatureAtAltitude(altitude);
	therm_cond average = (Atmosphere::getThermalConductivityOfAir(m_temperature) 
		+ Atmosphere::getThermalConductivityOfAir(temp)) / 2;

	joules heat = g_pGlobals->frametime * ((average * area * (m_temperature - temp)) / 0.01);
	if (pOtherVolume) {
		pOtherVolume->addEnergy(heat);
	}
	m_currentEnergy -= heat;
}

void Burner::AirVolume::updateParametersFromTemperature() {

}

void Burner::AirVolume::updateParametersFromEnergy() {

}

void Burner::Think() {
	float fuelToConsume = sqrtf(m_throttle);
	m_pFuelTank->consumeFuel(fuelToConsume);
	m_bottomState.addEnergy(m_throttle * 500 * m_pFuelTank->getFuelDensity());
	//m_bottomState.transferHeatTo(PI * sqr(m_bottomState->getRadius()), m_pForceAccumulator->getAircraftAltitude(), &m_topState);
	//m_topState.transferHeatTo((4 * PI * sqr(m_bottomState->getRadius()) / 2, m_pForceAccumulator->getAircraftAltitude());
}

void Burner::SetThrottleLevel(lerp _throttle) {
	m_throttle = _throttle;
}

newtons Burner::GetBuoyantForce() {
	return (Atmosphere::getAirDensityAtAltitude(m_pForceAccumulator->getAircraftAltitude()) * gravity * m_topState.getVolume());
}