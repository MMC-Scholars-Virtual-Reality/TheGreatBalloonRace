#include "Atmosphere.h"
#include "predefs.h"
#include <cmath>

namespace Atmosphere {

	static kelvin g_surfaceTemp = 287; //Surface temperature is 287 by default

	atmos getAirPressureAtAltitude(meters m) {
		return pow(euler, (-MOLAR_MASS_AIR * gravity * m / 1000) / (UNI_GAS_CONST * getAirTemperatureAtAltitude(m)));
	}

	kelvin getAirTemperatureAtAltitude(meters m) {
		return m * LAPSE_RATE + g_surfaceTemp;
	}

	density getAirDensityAtAltitude(meters m) {
		//return getAirPressureAtAltitude(m) / (SP_GAS_CONST_AIR * getAirTemperatureAtAltitude(m));
		//linear approximation
		float densityMetersCubed = 1.225 - 0.1 * (m / 1000);
		return densityMetersCubed / 1000; //kg/L
	}

	therm_cond getThermalConductivityOfAir(kelvin k) {
		float celsius = k - 273;
		return celsius * THERM_COND_AIR_RATE + THERM_COND_AIR_AT_ZERO_CELSIUS;
	}

	void setSurfaceTemperature(kelvin k) {
		g_surfaceTemp = k;
	}

}