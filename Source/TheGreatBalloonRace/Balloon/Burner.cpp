#include "Burner.h"
#include "VRBase/System/Globals.h"

Burner::AirVolume::AirVolume(const float _BalloonRadius) {
	m_radius = _BalloonRadius;

	//Use half-sphere volume equation
	m_volume = 2.f * 3.f * PI * powf(m_radius, 3);
}

void Burner::AirVolume::addEnergy(const joules heat) {

}

void Burner::AirVolume::transferHeatTo(meters area, kelvin outsideTemp, AirVolume* pOtherVolume) {
	//kelvin heat = 
}
