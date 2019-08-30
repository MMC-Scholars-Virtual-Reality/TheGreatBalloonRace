#include "Propeller.h"
#include "ForceAccumulator.h"
#include "Atmosphere.h"
#include "System/Globals.h"

#define max(a,b) ((a) < (b) ? (a) : (b))

Propeller::Propeller() {
	m_iNumBlades = 3;
	//m_dMass = 4;
	m_flBladeRadius = 5;
	m_nInertia = 1/3 * 4 * sqr(m_flBladeRadius);
	m_jCurrentEnergy = 0;
}
void Propeller::addEnergy(joules jEnergy)
{
	if (m_jCurrentEnergy < 0.001f)
		m_jCurrentEnergy = 0.001f;
	if (m_jCurrentEnergy && m_jCurrentEnergy > 1)
		m_jCurrentEnergy += jEnergy; // / max(sqr(m_jCurrentEnergy), 1);
	else
		m_jCurrentEnergy += jEnergy;
	/*if (m_jCurrentEnergy > 10)
		m_jCurrentEnergy = 10;
		*/
}
//get equation of prop strength based on rotational velocity, 
//forces and parameters we can actually control
newtons Propeller::getPropulsionStrength() const
{
	double area = PI * sqr(m_flBladeRadius); //area of the propeller disk
	double height = m_pfAccum->getAircraftAltitude(); //altitude of the aircraft
	double pressure = Atmosphere::getAirPressureAtAltitude(height); // air pressure
	//torque = rotational velocity^2, does not account for the other forces(blade pitch, etc)
	//final dynamic thrust F = 4.392399x10^-8 * RPM diameter(in inches)^(3.5)/(sqrt(pitch(in inches)) * (4.23333x10^-4) * RPM * pitch(in inches) - V0(velocity of hot air balloon + wind velocity)
	//final static thrust F = 1.225((pi(.0254 * d)^2)/4 * (RPM * 0.0245 * pitch(in inches) * 1min/60sec)^2 * (d/3.29546)^1.5
	//Thrust = pressure * area
	return pressure * area * 2 * sqrtf(m_jCurrentEnergy);
}

void Propeller::PreInit() {
	//m_jCurrentEnergy = 0;
	m_dRotationalVelo = 0;
}

//calculate rotational velocity based on energy, time, mass, and drag
void Propeller::think()
{
	//decay energy over time
	float drop = g_pGlobals->frametime * (1 + log10f(max(1,m_jCurrentEnergy)));
	//Msg("DROP: %f", drop);
	m_jCurrentEnergy -= drop;
	if (m_jCurrentEnergy < 0.001f)
		m_jCurrentEnergy = 0.001f;
		
	//Keep if numBlades is even
	//if numblades is even - m_nInertia = m_iNumBlades * (1 / 12.0) * m_dMass * sqr(2 * m_flBladeRadius);
	m_dRotationalVelo = (2 * m_jCurrentEnergy) / m_nInertia;

	/*
	v = tangential speed = rotational speed * r, r = radial distance
	Rotational Kinetic energy = .5 * rotational Inertia * rotSpeed
	angular velocity = rotational velocity = v/r
	drag = .5 * drag coefficient * density * area * velocity^2
	*/
}