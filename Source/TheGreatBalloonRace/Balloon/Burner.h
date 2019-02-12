#pragma once
#include "predefs.h"
/**
 * Burner models the main fuel burner which sends hot gas into the balloon, and also models
 * the state of the air inside the balloon
 */
class Burner {

	class AirVolume {

	private:
		liters m_volume;
		kelvin m_temperature;
		joules m_currentEnergy;
		meters m_radius;

	public:
		AirVolume(const float _AirVolume, const float _BalloonRadius);

		void addEnergy(const joules heat);

		void transferHeatTo(meters area, kelvin outsideTemp, AirVolume* pOtherVolume = nullptr);

	} m_bottomState, m_topState;

	void stopApplyingHeat();

};