#include "FuelTank.h"

FuelTank::FuelTank(const float _flFuelCapacity) {
	m_flFuelCapacity = _flFuelCapacity;
}

void FuelTank::consumeFuel(const float flAmount) {
	m_flFuelCurrent -= flAmount;
	
}

bool FuelTank::canConsumeFuel(const float flAmount) const {

}

float FuelTank::getFuelCurrent() const {
	return m_flFuelCurrent;
}

float FuelTank::getFillRatio() const
{

}

float FuelTank::getFuelConsumptionRate() const
{

}

