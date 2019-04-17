#pragma once

#include "VRBase/System/predefs.h"
#include "Propeller.h"
#include "UnrealEngine.h"
#include "Sound/SoundCue.h"
#include "Components/AudioComponent.h"

//Forward declaration of class
class FuelTank;
class ForceAccumulator;

class PropellerEngine {
	friend class ForceAccumulator;
	friend class AHotAirBalloon;
public:
	// Constructor
	PropellerEngine();
public:
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
	ABaseEntity* m_pSoundLocation;


	//Settings set by in-world throttels
	lerp m_lMainThrottle; //0-1 scale
	lerp m_lRudderThrottle; //0-1 scale

	//Engine state variables
	constexpr static uint8 NUM_GEARS = 4;
	constexpr static uint16 RPMperGear = 1000;
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
	//implemented
	void playEngineSound();

	//implemented
	uint16 getGearIndepRPM();
	
	//implemented
	void setByGearIndepRPM(uint16 indepRPM);
/**
 * Public functions
 */
public:

	void PreInit();

	//implemented
	void setThrottle(lerp _flThrottle, EThrottle eThrottle);
	
	//implemented
	void setSoundCue(USoundCue* sound) { m_pEngineSound = sound; }
	
	//implemented
	void think(ForceAccumulator* pAccumulator);

	//implemented
	void setRPM(uint16 RPM) { m_iRPM = RPM; }
	
	//implemented
	void setGear(uint8 gear) { m_iCurrentGear = gear; }
		
};