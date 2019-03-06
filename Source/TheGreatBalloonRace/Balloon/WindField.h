#pragma once
#include "Force.h"
#include "predefs.h"
#include "ForceAccumulator.h"

class ForceAccumulator;
namespace WindField {


	//implemented
	void think(ForceAccumulator* pAccumulator);
	//implemented
	FVector GetWindAtAltitude(meters m);
	
};
