#include "Burner.h"
#include "VRBase/System/Globals.h"

Burner::AirVolume::AirVolume(const float _AirVolume, const float _BalloonRadius) {
	m_volume = _AirVolume;
	m_radius = _BalloonRadius;
}

void Burner::AirVolume::addEnergy(const joules heat) {

}

void Burner::AirVolume::transferHeatTo(meters area, kelvin outsideTemp, AirVolume* pOtherVolume) {
	kelvin heat = 
}

void Burner::stopApplyingHeat() {

}