#include "Propeller.h"


void Propeller::addEnergy(joules jEnergy)
{
    m_currentEnergy += jEnergy;
}
//get equation of prop strength based on rotational velocity, forces and parameters we can actually control
newtons Propeller::getPropulsionStrength()
{
    double density = 0; //air density
    double area = 0; //area of the propeller, modified by the number of blades
    double exitV = 0; //the velocity of the air leaving the propeller
    double aircraftV = 0; //the velocity of the aircraft
    m_propStrength = .50 * density * area * (sqr(exitV) - sqr(aircraftV));
    return m_propStrength;
}
		//calculate rotational velocity based on energy, time, mass, and drag
void Propeller::think()
{
    
}

