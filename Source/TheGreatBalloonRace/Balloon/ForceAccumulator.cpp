#include "ForceAccumulator.h"
#include "System/NLogger.h"
#include "ABaseEntity/ABaseEntity.h"
#include "predefs.h"

meters ForceAccumulator::getAircraftAltitude() {
	return 0; //Returns the altitude of the aircraft
}

void ForceAccumulator::reset() {
	m_forces.Empty(); //Empties the force vectors
}

FVector ForceAccumulator::getSummedForces() {
	//m_pBalloon->
	const float massOfBalloon = 400;
	Force gravitation = Force{ Force::GRAVITY, FVector(0, 0, -massOfBalloon * gravity) };
	addForce(gravitation);

	//const float baseDrag = 50;
	Force drag = Force{ Force::DRAG, -m_pBalloon->GetVelocity() };
	addForce(drag);

	//Checks if there are the required amount of forces in the force array
	if (m_forces.Num() != Force::NUM_FORCES) {
		NLogger::Warning("In" __FUNCTION__ "There are not the required amount of forces.");
	}

	FVector forceSum; //Create a vector that holds the sum of the forces

	for (int i = 0; m_forces.Num(); i++) { //Loop through the array 
		forceSum += m_forces[i].m_vector; //and add all the forces together
	}

	return forceSum; //Return the sum of the forces
}

void ForceAccumulator::addForce(const Force& F) {
	for (int i = 0; i < m_forces.Num(); i++) {
		if (m_forces[i].m_eForceType != F.m_eForceType) {
			m_forces.Add(F);
		}
		else {
			NLogger::Warning("In" __FUNCTION__ "Recieved duplicate of type.");
		}
	}
}

void ForceAccumulator::Think() {
	m_burner.think();
	m_propellerEngine.think();
}