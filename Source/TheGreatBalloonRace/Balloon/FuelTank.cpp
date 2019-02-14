#include "FuelTank.h"
#include "VRBase/System/Globals.h"
#include "predefs.h"

FuelTank::FuelTank(const float _flFuelCapacity) {
	m_flFuelCapacity = _flFuelCapacity;
	m_flFuelCurrent = _flFuelCapacity;
}

void FuelTank::consumeFuel(const float flAmount) {
	m_flFuelCurrent -= flAmount;
	if (m_tLastFuelConsumptionTime != g_pGlobals->curtime) {
		m_tLastFuelConsumptionTime = g_pGlobals->curtime;
		m_flLastFuelAmountConsumed = 0;
	}
	m_flLastFuelAmountConsumed += flAmount;
}

bool FuelTank::canConsumeFuel(const float flAmount) const {
	return (flAmount < m_flFuelCurrent); //Returns true if the fuel can be consumed 
}

float FuelTank::getFuelCurrent() const {
	return m_flFuelCurrent;
}

float FuelTank::getFillRatio() const {
	return (m_flFuelCurrent / m_flFuelCapacity);
}

float FuelTank::getFuelConsumptionRate() const {
	return (m_flLastFuelAmountConsumed / g_pGlobals->frametime); 
}

float FuelTank::getFuelDensity() const {
	float flDensity = log(getFillRatio()*10 + 1);
	return min(flDensity, 1);
}

void FuelTank::refuel(const float reflAmount) {
	m_flFuelCurrent += reflAmount;
}
