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
	lerp m_lMainThrottle; //0-1 scale
	lerp m_lRudderThrottle; //0-1 scale

	//Engine state variables
	constexpr static uint8 NUM_GEARS = 4;
	const static uint8 RPMperGear = 1000;
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
	void checkGearChange(uint8 m_iCurrentGear);
	uint16 getGearIndepRPM();
	uint16 setByGearIndepRPM(uint16 indepRPM);
/**
 * Public functions
 */
public:

	void setThrottle(lerp _flThrottle, EThrottle eThrottle);

	void setSoundCue(USoundCue* sound) { m_pEngineSound = sound; }

	void think();

	void setRPM(uint16 RPM);

	void setGear(uint8 RPM);
	
};