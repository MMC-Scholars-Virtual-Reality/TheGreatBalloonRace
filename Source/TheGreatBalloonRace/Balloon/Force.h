#pragma once
#include "KismetClasses.h"

struct Force {

	/*
	Type of force
	*/
	enum EForceType : unsigned char {
		PROPULSION,
		DRAG,
		GRAVITY,
		BUOYANCY,
		WIND
	} m_eForceType;

	/*
	Direction and strength of force
	*/
	FVector m_vector;

};