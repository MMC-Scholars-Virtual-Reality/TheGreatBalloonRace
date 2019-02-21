#pragma once
#include "Force.h"
#include "UnrealEngine.h"
#include "predefs.h"

class ForceAccumulator {
public:

	meters getAircraftAltitude();

	void reset();

	Force getSummedForces() const;

	void addForce(const Force& F);

private:
	TArray<Force> m_forces;

};