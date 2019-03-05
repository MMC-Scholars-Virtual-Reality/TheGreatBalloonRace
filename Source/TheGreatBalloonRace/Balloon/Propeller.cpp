#include "Propeller.h"
#include "ForceAccumulator.h"
#include "Atmosphere.h"


void Propeller::addEnergy(joules jEnergy)
{
	m_jCurrentEnergy += jEnergy;
}
//get equation of prop strength based on rotational velocity, 
//forces and parameters we can actually control
newtons Propeller::getPropulsionStrength()
{
	//double density; //air density
	double area = 0; //area of the propeller disk
	double exitV = 0; //the velocity of the air leaving the propeller
	double aircraftV = 0; //the velocity of the aircraft
	double pressure = 0; // air pressure
	double density = 0; //density of the air normally 1.225 kg/m^3
	double height = 0; //altitude of the aircraft

	//torque = rotational velocity^2, does not account for the other forces(blade pitch, etc)
	//final dynamic thrust F = 4.392399x10^-8 * RPM diameter(in inches)^(3.5)/(sqrt(pitch(in inches)) * (4.23333x10^-4) * RPM * pitch(in inches) - V0(velocity of hot air balloon + wind velocity)
	//final static thrust F = 1.225((pi(.0254 * d)^2)/4 * (RPM * 0.0245 * pitch(in inches) * 1min/60sec)^2 * (d/3.29546)^1.5
	
	//m_nPropStrength = m_dRotationalVelo * c;
	//m_nPropStrength = .50 * density * area * (sqr(exitV) - sqr(aircraftV));
	
	//Thrust = pressure * area
	area = PI * sqr(m_flBladeRadius); 
	height = m_pfAccum->getAircraftAltitude();
	pressure = Atmosphere::getAirPressureAtAltitude(height);
	m_nPropStrength = pressure * area;
	
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
