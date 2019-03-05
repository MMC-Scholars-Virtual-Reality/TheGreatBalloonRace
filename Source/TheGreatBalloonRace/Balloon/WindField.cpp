#include "WindField.h"	

namespace WindField {

	FVector m_vDirections[10];
	FVector WindVector;
	void SetWind() {
		for (int i = 0; i < m_vDirections->Size(); i++) {
			WindVector.X = FMath::FRandRange(0, 100);
			WindVector.Y = FMath::FRandRange(0, 100);
			WindVector.Z = FMath::FRandRange(0, 100);
			m_vDirections[i].Set(WindVector.X, WindVector.Y, WindVector.Z);
		}
	}

	FVector GetWindAtAltitude(meters m) {
		int index = fmod(m, 10);
		return m_vDirections[index];
	}
}