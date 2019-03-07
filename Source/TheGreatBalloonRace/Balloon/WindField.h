#pragma once
#include "Force.h"
#include "predefs.h"
#include "ForceAccumulator.h"

class ForceAccumulator;
namespace WindField {
	//implemented
	void setWinds(ForceAccumulator* pAccumulator);
	//implemented
	FVector GetWindAtAltitude(meters m);
	
};
