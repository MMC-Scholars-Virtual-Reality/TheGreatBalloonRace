#include "FuelTank.h"
#include "VRBase/System/Globals.h"
#include "predefs.h"

FuelTank::FuelTank(const float _flFuelCapacity) {
	m_flFuelCapacity = _flFuelCapacity;
	m_flFuelCurrent = _flFuelCapacity;
} //Constructs a fuel tank with the given capacity and sets the current fuel level to the capacity

void FuelTank::consumeFuel(const float flAmount) {
	m_flFuelCurrent -= flAmount; //Subtracts fuel from the current fuel amount
	if (m_tLastFuelConsumptionTime != g_pGlobals->curtime) { //If the last time fuel was consumed is not the same as the current time
		m_tLastFuelConsumptionTime = g_pGlobals->curtime;    //Make the last time fuel was consumed the current time and
		m_flLastFuelAmountConsumed = 0;                      //reset the last fuel amount consumed to 0
	}
	m_flLastFuelAmountConsumed += flAmount; //Increase the last fuel amount consumed by the amount that was just subtracted
}

bool FuelTank::canConsumeFuel(const float flAmount) const {
	return (flAmount < m_flFuelCurrent); //Returns true if the fuel can be consumed 
}

float FuelTank::getFuelCurrent() const {
	return m_flFuelCurrent; //Returns the current amount of fuel
}

float FuelTank::getFillRatio() const {
	return (m_flFuelCurrent / m_flFuelCapacity); //Returns the proportion of fuel to fuel capacity
}

float FuelTank::getFuelConsumptionRate() const {
	return (m_flLastFuelAmountConsumed / g_pGlobals->frametime);  //Returns the rate at which fuel is consumed in frametime
}

float FuelTank::getFuelDensity() const {
	float flDensity = log(getFillRatio()*10 + 1);
	return min(flDensity, 1); //Returns the density of the fuel that can be used, decreases as it approaches 0
}

void FuelTank::refuel(const float reflAmount) {
	m_flFuelCurrent += reflAmount; //Adds an amount of fuel to the current fuel
}
