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
	class AirVolume {

	private:
		meters m_volume;
		kelvin m_temperature;
		joules m_currentEnergy;
		meters m_radius;

	public:
		/**
		* Constructor initializes the balloon's variables
		* @param _BalloonRadius - the radius of the balloon
		* @param _currentEnergy - the current energy of the air inside the balloon
		* @param _temperature - the temperature of the air inside the balloon
		*/
		AirVolume(const float _BalloonRadius, const float _currentEnergy, const float _temperature);

		/**
		* Given an amount of heat, adds it to the current energy of the balloon
		* @param heat - the amount of energy to add
		* @updates m_currentEnergy
		*/
		void addEnergy(const joules heat);

		/**
		* Given an area, altitude, and other volume, transfers heat to the other volume using
		* heat diffusion equations
		* @param area - the area of the boundary separating the two volumes
		* @param altitude - the height of the balloon
		* @param pOtherVolume - the other volume that heat is being transferred to
		*/
		void transferHeatTo(meters area, meters altitude, AirVolume* pOtherVolume = nullptr);

		//Based on temperature and other parameters, updates energy
		void updateParametersFromTemperature();

		//Based on energy and other parameters, updates temperature
		void updateParametersFromEnergy();

		/**
		* @return m_volume
		*/
		meters getVolume() const { return m_volume; }

		/**
		* @return m_radius
		*/
		meters getRadius() const { return m_radius; }

	} m_bottomState, m_topState;

	//Fuel tank to consume from
	FuelTank* m_pFuelTank;

	ForceAccumulator* m_pForceAccumulator;

	lerp m_throttle; //Is the burner on or off, on a range from 0 to 1

public:
	//Called on each frame
	//Based on the throttle level, consumes an amount of fuel from the fueltank
	//and adds energy to m_bottomState
	void Think();

	//Based on atmospheric conditions and m_topState, calculates a buoyant force in newtons
	newtons GetBuoyantForce();

	//Given a throttle level sets the throttle to the given level
	void SetThrottleLevel(lerp _throttle);
};