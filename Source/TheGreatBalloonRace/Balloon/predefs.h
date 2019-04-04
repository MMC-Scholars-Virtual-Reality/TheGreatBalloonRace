#pragma once

typedef float joules;
typedef float newtons;
typedef float liters;
typedef float meters;
typedef float kelvin;
typedef float atmos;
typedef float kilos;
typedef float density; //kg/L
typedef float therm_cond;
#define min(a, b) ((a) < (b) ? a : b)
#define sqr(a) ((a)*(a))
#define gravity (9.81)
#define euler (2.71828)
#define MOLAR_MASS_AIR (0.002896) //kilos/mol
#define UNI_GAS_CONST (0.0821) //L-atm / mol-K
#define SP_GAS_CONST_AIR (287.05)
#define BOLTZMANN_CONSTANT  (1.38064852e-23f)
#define LAPSE_RATE (-0.0065) //In kelvin per meter
#define THERM_COND_AIR_RATE (0.0000777333)
#define THERM_COND_AIR_AT_ZERO_CELSIUS (0.02436)

enum EThrottle : unsigned char {
	THROTTLE_MAIN,
	THROTTLE_RUDDER,
};