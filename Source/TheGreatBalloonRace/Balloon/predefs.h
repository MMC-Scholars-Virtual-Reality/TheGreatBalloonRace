#pragma once

typedef float joules;
typedef float newtons;
typedef float liters;
typedef float meters;
typedef float kelvin;
typedef float atmos;
typedef float density;
typedef float therm_cond;
#define min(a, b) ((a) < (b) ? a : b)
#define sqr(a) ((a)*(a))
#define gravity 9.81
#define BOLTZMANN_CONSTANT  (1.38064852e-23f)

enum EThrottle : unsigned char {
	THROTTLE_MAIN,
	THROTTLE_RUDDER,
};