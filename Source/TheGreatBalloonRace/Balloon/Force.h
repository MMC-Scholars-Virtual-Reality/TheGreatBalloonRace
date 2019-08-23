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
		WIND,
		NUM_FORCES
	} m_eForceType;

	/*
	Direction and strength of force
	*/
	FVector m_vector;

	inline FString getAsString() const {
		const char* pre = "UNKNOWN";
		switch (m_eForceType) {
		case PROPULSION: pre = "PROPULSION"; break;
		case DRAG: pre = "DRAG"; break;
		case GRAVITY: pre = "GRAVITY"; break;
		case BUOYANCY: pre = "BUOYANCY"; break;
		case WIND: pre = "WIND"; break;
		}

		FString result = pre;
		char buffer[64];
		sprintf_s(buffer, " (%.2f, %.2f, %.2f)", m_vector.X, m_vector.Y, m_vector.Z);
		result += buffer;
		return result;
	}

};