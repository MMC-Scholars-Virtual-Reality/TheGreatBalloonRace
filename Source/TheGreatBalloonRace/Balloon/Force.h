#pragma once
#include "KismetClasses.h"

struct Force {

	/*
	Type of force
	*/
	enum EForceType : unsigned char {
		PROPULSION = 0,
		DRAG,
		GRAVITY,
		BUOYANCY,
		WIND,
		NUM_FORCES
	} m_eForceType;

	/*
	Direction and strength of force
	*/
	FVector m_vector;

};