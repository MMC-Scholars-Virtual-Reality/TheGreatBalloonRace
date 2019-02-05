#pragma once

#include "VRBase/System/predefs.h"
#include "Propeller.h"
#include "UnrealEngine.h"
#include "Sound/SoundCue.h"

//Forward declaration of class
class FuelTank;

class PropellerEngine {

/**
 * Private member variables
 */
private:
	
	//The fuel tank to consume fuel from
	FuelTank * m_pFuelTank;

	//Two propellers - Main and Rudder
	Propeller m_mainPropeller;
	Propeller m_rudderPropeller;
	
	//Use the forward vectors of these as the directions of the propeller forces.
	ABaseEntity* m_mainPropellerDirection;
	ABaseEntity* m_rudderPropellerDirection;

	//Settings set by in-world throttels
	lerp m_flMainThrottel; //0-1 scale
	lerp m_flRudderThrottel; //0-1 scale

	//Engine state variables
	constexpr static uint8 NUM_GEARS = 4;
	uint8 m_iCurrentGear;
	uint16 m_iRPM;

	//Engine sound
	USoundCue* m_pEngineSound;

/**	
 * Private member helper functions
 */
private:

	/**
	 * Ensures that the engine sound is currently being played with the correct parameters.
	 */
	void playEngineSound();


/**
 * Public functions
 */
public:



};