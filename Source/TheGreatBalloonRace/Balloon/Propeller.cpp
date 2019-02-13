#include "Propeller.h"


void Propeller::addEnergy(joules jEnergy)
{
	m_jCurrentEnergy += jEnergy;
}
//get equation of prop strength based on rotational velocity, 
//forces and parameters we can actually control
newtons Propeller::getPropulsionStrength()
{
	double density = 1.225; //air density
	double area = 0; //area of the propeller disk
	double exitV = 0; //the velocity of the air leaving the propeller
	double aircraftV = 0; //the velocity of the aircraft
	//torque = rotational velocity^2, does not account for the other forces(blade pitch, etc)
	//F = 4.392399x10^-8 * RPM diameter(in inches)^(3.5)/(sqrt(pitch(in inches)) * (4.23333x10^-4) * RPM * pitch(in inches) - V0(propeller forward airspeed)
	//static thrust if V0 = 0
	m_nPropStrength = .50 * density * area * (sqr(exitV) - sqr(aircraftV));
	return m_nPropStrength;
}
//calculate rotational velocity based on energy, time, mass, and drag
void Propeller::think()
{
	//Keep if numBlades is even
	m_nInertia = m_iNumBlades * (1 / 12.0) * m_dMass * sqr(2 * m_flBladeRadius);
	//USE IF NUMBLADES IS ODD - inertia = 1/3 * m_mass * sqr(r);
	m_dRotationalVelo = (2 * m_jCurrentEnergy) / m_nInertia;
	/*
	v = tangential speed = rotational speed * r, r = radial distance
	Rotational Kinetic energy = .5 * rotational Inertia * rotSpeed
	angular velocity = rotational velocity = v/r
	drag = .5 * drag coefficient * density * area * velocity^2
	*/
}
