#pragma once

#include "predefs.h"
#include "VRBase/System/predefs.h"

class Propeller {
/*
 * Private member variables
 */
private:
	
	uint8		m_iNumBlades; //number of blades on the propeller
	vec			m_flBladeRadius; //the radius of the blade on the propeller
	newtons		m_propStrength; //the strength of the propulsion/thrust of the propeller
	double 		m_area; //surface area of the propeller disk, looking at it from the front(circle)
	double		m_rotationalVelo; //revolutions per second of the propeller
	double 		m_mass; //mass of the propeller
	
	//TODO - add member variables needed for physics-based model of propeller
/*
 * Public members
 */
public:
	joules		m_currentEnergy = 0;
	/*
	 * Adds energy to be converted into rotational energy of the propeller.
	 */
	void addEnergy(joules jEnergy);

	/**
	 * Based on current rotational velocity, blade radius, and number of blades,
	 * Returns a force in newtons to be applied to a ForceAccumulator, same as thrust???
	 * 
	 */
	newtons getPropulsionStrength();

	/**
	 * Models the decay of energy over time
	 */
	void think();

};
