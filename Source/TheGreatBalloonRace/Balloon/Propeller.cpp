#include "Propeller.h"
#include "Windows.h"


void Propeller::addEnergy(joules jEnergy)
{
    m_currentEnergy += jEnergy;
}
//get equation of prop strength based on rotational velocity, forces and parameters we can actually control
newtons Propeller::getPropulsionStrength()
{
    double density; //air density
    double area; //area of the propeller, modified by the number of blades
    double exitV; //the velocity of the air leaving the propeller
    double aircraftV; //the velocity of the aircraft
    m_propStrength = .50 * density * area *((Math.pow(exitV, 2) - Math.pow(aircraftV, 2));
    return m_propStrength;
}
		//calculate rotational velocity based on energy, time, mass, and drag
void Propeller::think()
{
    
}

