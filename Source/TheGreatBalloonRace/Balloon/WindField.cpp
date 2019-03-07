#include "WindField.h"	
#include "ForceAccumulator.h"

namespace WindField {
	const int numOfAltitudes = 10;
	FVector m_vDirections[numOfAltitudes]; //array of wind vectors
	FVector WindVector; //wind vector inserted into the array
	//sets the wind at each altitude and sends the force to Force Accumuator
	void setWinds(ForceAccumulator* pAccumulator) {
		for (int i = 0; i < m_vDirections->Size(); i++) {
			WindVector.X = FMath::FRandRange(0, 1);
			WindVector.Y = FMath::FRandRange(0, 1);
			WindVector.Z = FMath::FRandRange(0, 1);
			m_vDirections[i].Set(WindVector.X, WindVector.Y, WindVector.Z);
			meters m = pAccumulator->getAircraftAltitude();
			WindVector = GetWindAtAltitude(m);
			pAccumulator->addForce(Force{ Force::WIND, WindVector });
		}
	}
	//gets the wind at specific altitude
	FVector GetWindAtAltitude(meters m) {
		int index = fmod(m, 10);
		return m_vDirections[index];
	}
}