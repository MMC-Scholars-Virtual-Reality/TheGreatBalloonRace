#pragma once
#include "predefs.h"

namespace Atmosphere {

	atmos getAirPressureAtAltitude(meters m);

	kelvin getAirTemperatureAtAltitude(meters m);

	density getAirDensityAtAltitude(meters m);

	therm_cond getThermalConductivityOfAir(kelvin k);
}