#include "ForceAccumulator.h"
#include "System/NLogger.h"
#include "predefs.h"

meters ForceAccumulator::getAircraftAltitude() {
	return 0;
}

void ForceAccumulator::reset() {
	m_forces.Empty();
}

Force ForceAccumulator::getSummedForces() const {
	if (m_forces.Num() != Force::NUM_FORCES) {
		NLogger::Warning("In" __FUNCTION__ "There are not the required amount of forces.");
	}
	return Force();
}