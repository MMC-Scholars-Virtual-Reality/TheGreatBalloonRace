#include "WindField.h"	
#include "ForceAccumulator.h"

namespace WindField {
	const int numOfAltitudes = 10;
	FVector m_vDirections[numOfAltitudes];
	FVector WindVector;
	/*runs every second of the program. Constantly changes the wind direction
	depending on each altitude. Then takes the altitude of the aircraft
	and adds the correct wind to the force accummulator
	*/
	void think(ForceAccumulator* pAccumulator) {
		for (int i = 0; i < m_vDirections->Size(); i++) {
			WindVector.X = FMath::FRandRange(0, 100);
			WindVector.Y = FMath::FRandRange(0, 100);
			WindVector.Z = FMath::FRandRange(0, 100);
			m_vDirections[i].Set(WindVector.X, WindVector.Y, WindVector.Z);
		}
		//maybe normalize()?
		meters m = pAccumulator->getAircraftAltitude();
		WindVector = GetWindAtAltitude(m);
		pAccumulator->addForce(Force{ Force::WIND, WindVector });
	}
	//gets the wind at specific altitude
	FVector GetWindAtAltitude(meters m) {
		int index = fmod(m, 10);
		return m_vDirections[index];
	}

	
}