#include "ForceAccumulator.h"
#include "System/NLogger.h"
#include "ABaseEntity/ABaseEntity.h"
#include "HotAirBalloon.h"
#include "Atmosphere.h"
#include "predefs.h"

ForceAccumulator::ForceAccumulator() : m_burner(5, 1000) {
	m_pBalloon = NULL;
	m_burner.m_pFuelTank = &m_fuelTank;
	m_burner.m_pForceAccumulator = this;
	m_propellerEngine.m_pFuelTank = &m_fuelTank;
}

meters ForceAccumulator::getAircraftAltitude() const {
	return m_pBalloon->GetActorLocation().Z / 100; //Returns the altitude of the aircraft
}

void ForceAccumulator::reset() {
	m_forces.Empty(); //Empties the force vectors
}

FVector ForceAccumulator::getSummedForces() {
	
	float massOfBalloon = m_pBalloon->GetMass();
	Force gravitation = Force{ Force::GRAVITY, FVector(0, 0, -massOfBalloon * gravity) };
	addForce(gravitation);

	//const float baseDrag = 50;
	Force drag = Force{ Force::DRAG, 100 * -m_pBalloon->GetVelocity() };
	addForce(drag);

	//Checks if there are the required amount of forces in the force array
	/*if (m_forces.Num() != Force::NUM_FORCES) {
		NLogger::Warning("In" __FUNCTION__ "There are not the required amount of forces.");
	}*/

	FVector forceSum = FVector(0); //Create a vector that holds the sum of the forces
	for (int i = 0; i < m_forces.Num(); i++) { //Loop through the array 
		forceSum += m_forces[i].m_vector; //and add all the forces together
	}
	forceReport();
	m_forces.Empty();
	return forceSum; //Return the sum of the forces
}

void ForceAccumulator::addForce(const Force& F) {
	bool duplicate = false;
	for (int i = 0; i < m_forces.Num() && !duplicate; i++) {
		duplicate = m_forces[i].m_eForceType == F.m_eForceType;
	}

	if (!duplicate) {
		m_forces.Add(F);
	}
	else {
		NLogger::Warning("In" __FUNCTION__ "Recieved duplicate of type.");
	}
}

void ForceAccumulator::Think() {
	m_burner.think();
	m_propellerEngine.think(this);
}

void ForceAccumulator::forceReport() const {
	static int frameCounter = 0;
	frameCounter++;
	if (frameCounter == 100) {
		frameCounter = 0;
		for (int32 i = 0; i < m_forces.Num(); i++) {
			Msg(m_forces[i].getAsString());
		}

		FVector v = m_pBalloon->GetVelocity();
		Msg("Velocity: (%f, %f, %f) m/s", v.X, v.Y, v.Z);
		Msg("Mass: %fkg", m_pBalloon->GetMass());
		Msg("AirDensity: %f", Atmosphere::getAirDensityAtAltitude(getAircraftAltitude()));
		Msg("AirTemperature: %f", Atmosphere::getAirTemperatureAtAltitude(getAircraftAltitude()));
		Msg("AirPressure: %f", Atmosphere::getAirPressureAtAltitude(getAircraftAltitude()));
		Msg("BalloonDensity: %f", m_burner.GetDensity());
		Msg("BalloonTemp: %f", m_burner.GetTemperature());
		//Msg("Propulsion: %f", m_propellerEngine.m_mainPropeller.getPropulsionStrength());
		Msg("\n");
	}
}
