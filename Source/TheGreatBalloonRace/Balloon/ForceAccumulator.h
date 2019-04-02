#pragma once
#include "Force.h"
#include "Burner.h"
#include "PropellerEngine.h"
#include "FuelTank.h"
#include "UnrealEngine.h"
#include "predefs.h"

class AHotAirBalloon;

class ForceAccumulator {
	friend class AHotAirBalloon;
public:

	ForceAccumulator();

	//Returns the atltitude of the aircraft
	meters getAircraftAltitude();

	//Resets the forces on the aircraft
	void reset();

	//Sums all the forces on the aircraft and
	//returns the net force vector
	FVector getSummedForces();

	//Add a force vector to the array of forces
	void addForce(const Force& F);

	void Think();


private:

	//An array of the forces on the aircraft
	//Includes propulsion, drag, gravity, buoyancy,
	//and wind
	TArray<Force> m_forces; 
	Burner m_burner;
	PropellerEngine m_propellerEngine;
	FuelTank m_fuelTank;
	AHotAirBalloon* m_pBalloon;


	
};