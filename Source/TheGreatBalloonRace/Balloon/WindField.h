#pragma once
#include "Force.h"
#include "predefs.h"
#include "ForceAccumulator.h"

class ForceAccumulator;
namespace WindField {
	//implemented
	void GenerateWinds();
	FVector GetWindDirectionAtAltitude(meters m);
	//implemented
	Force GetWindForceAtAltitude(meters m);
	
};
