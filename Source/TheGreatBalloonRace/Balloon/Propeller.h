#pragma once

#include "predefs.h"
#include "VRBase/System/predefs.h"

class ForceAccumulator;
class Propeller {
	friend class AHotAirBalloon;
	/*
	* Private member variables
	*/
private:

	uint8		m_iNumBlades; //number of blades on the propeller
	vec			m_flBladeRadius; //the radius of the blade on the propeller
	newtons		m_nPropStrength; //the strength of the propulsion/thrust of the propeller
	double 		m_dArea; //surface area of the propeller disk, looking at it from the front(circle)
	double 		m_dMass; //mass of the propeller

	//TODO - add member variables needed for physics-based model of propeller
	/*
	* Public members
	*/
public:
	joules			m_jCurrentEnergy; //the current energy being given to the propellers
	newtons			m_nInertia; //the moment of inertia of the propeller
	double			m_dRotationalVelo; //revolutions per second of the propeller
	ForceAccumulator* m_pfAccum; 
	
	Propeller();
	
	/*
	* Adds energy to be converted into rotational energy of the propeller.
	*/
	//implemented
	void addEnergy(joules jEnergy);



	/**
	* Based on current rotational velocity, blade radius, and number of blades,
	* Returns a force in newtons to be applied to a ForceAccumulator
	*
	*/
	newtons getPropulsionStrength() const;
	
	
	/**
	* Models the decay of energy over time
	*/
	//implemented
	void think();

};
