#pragma once

typedef float joules;
typedef float newtons;
typedef float liters;
typedef float meters;
typedef float kelvin;
#define min(a, b) ((a) < (b) ? a : b)
#define sqr(a) ((a)*(a))

enum EThrottel : unsigned char {
	THROTTEL_MAIN,
	THROTTEL_RUDDER,
};