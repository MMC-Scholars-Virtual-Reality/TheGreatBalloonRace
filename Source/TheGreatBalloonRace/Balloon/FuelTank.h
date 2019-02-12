#pragma once

#include "VRBase/System/predefs.h"

class FuelTank {

/*
 * Private member variables
 */
private:
	float m_flFuelCurrent; //current amount of fuel in the tank
	float m_flFuelCapacity; //capacity of the tank

	ftime m_tLastFuelConsumptionTime; //The last frame that fuel was consumed on
	float m_flLastFuelAmountConsumed; //how much fuel has been consumed on this frame?
/*
 * Public members
 */
public:

	/**
	 * Constructor builds a fuel tank with the given fuel capacity
	 * @param _flFuelCapacity - the capacity of the tank, in arbitrary units.
	 */
	FuelTank(const float _flFuelCapacity);

	/**
	 * Given an amount of fuel, consumes it from the tank.
	 * @param flAmount - the amount of fuel to consume
	 * @requires flAmount > getFuelCurrent()
	 * @updates m_flFuelCurrent, m_tLastFuelConsumptionTime, m_flLastFuelAmountConsumed
	 */
	void consumeFuel(const float flAmount);

	/**
	 * Given an amount of fuel, checks if that amount can be consumed.
	 * @param flAmount - the amount of fuel to check
	 * @return flAmount < getFuelCurrent()
	 */
	bool canConsumeFuel(const float flAmount) const;

	/**
	 * @return the current amount of fuel in the tank
	 */
	float getFuelCurrent() const;

	/**
	 * @return the current amount of fuel in the tank, in a 0-1 proportion scale of the capacity.
	 */
	float getFillRatio() const;

	/**
	 * @return the fuel consumption rate, in units/s.
	 */
	float getFuelConsumptionRate() const;

	/**
	* @return flDensity
	*/
	float getFuelDensity() const;

	/**
	* Given an amount of fuel, adds that amount to the tank
	* @param reflAmount - the amount of fuel to add
	* @requires reflAmount < (_flFuelCapacity - getFuelCurrent)
	*/
	void refuel(const float reflAmount);
};