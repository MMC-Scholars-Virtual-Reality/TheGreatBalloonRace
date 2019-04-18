#pragma once
#include "predefs.h"
#include "System/predefs.h"

class FuelTank;
class ForceAccumulator;

/**
 * Burner models the main fuel burner which sends hot gas into the balloon, and also models
 * the state of the air inside the balloon
 */
class Burner {
private:
	friend class ForceAccumulator;

	//Fuel tank to consume from
	FuelTank* m_pFuelTank;

	ForceAccumulator* m_pForceAccumulator;

	lerp m_throttle; //Is the burner on or off, on a range from 0 to 1

	liters m_Volume;

	kelvin m_Temperature;



public:
	Burner(const float _BalloonRadius);

	//Called on each frame
	//Based on the throttle level, consumes an amount of fuel from the fueltank
	//and adds energy to m_bottomState
	void think();

	//Based on atmospheric conditions and m_topState, calculates a buoyant force in newtons
	newtons GetBuoyantForce();

	//Given a throttle level sets the throttle to the given level
	void SetThrottleLevel(lerp _throttle);
	lerp GetThrottleLevel() const { return m_throttle; }

	//Gets the mass of the air inside the balloon
	kilos GetAirMass() const;

	density GetDensity() const;

	inline kelvin GetTemperature() const { return m_Temperature; }

	inline void SetTemperature(kelvin temperature) { m_Temperature = temperature; }
};