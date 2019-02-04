#pragma once

#include "predefs.h"
#include "VRBase\System\predefs.h"

class Propeller {
/*
 * Private member variables
 */
private:
	
	uint8	m_iNumBlades;
	vec		m_flBladeRadius;

	//TODO - add member variables needed for physics-based model of propeller
/*
 * Public members
 */
public:

	/*
	 * Adds energy to be converted into rotational energy of the propeller.
	 */
	void addEnergy(joules jEnergy);

	/**
	 * Based on current rotational velocity, blade radius, and number of blades,
	 * Returns a force in newtons to be applied to a ForceAccumulator
	 * 
	 */
	newtons getPropulsionStrength();

};