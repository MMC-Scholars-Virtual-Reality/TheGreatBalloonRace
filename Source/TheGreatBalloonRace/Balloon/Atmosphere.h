#pragma once
#include "predefs.h"

namespace Atmosphere {

	//Given a temperature, sets the surface temperature to that temperature
	void setSurfaceTemperature(kelvin k);

	//Given an altitude, calculates the air pressure at that given altitude
	//Uses getAirTemperatureAtAltitude
	atmos getAirPressureAtAltitude(meters m);

	//Given an altitide, calculates the air temperature at that given altitude
	kelvin getAirTemperatureAtAltitude(meters m);

	//Given an altitude, calculates the air density at that given altitude
	//Uses getAirPressureAtAltitude and getAirTemperatureAtAltitude
	density getAirDensityAtAltitude(meters m);

	//Given a temperature, approximates the thermal conductivity of air at that temperature
	therm_cond getThermalConductivityOfAir(kelvin k);
}