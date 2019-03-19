#include "WindField.h"	
#include "ForceAccumulator.h"

namespace WindField {
	const int NUM_ALTITUDES = 10;
	const float WIND_FORCE_MULTIPLIER = 10;
	FVector g_avDirections[NUM_ALTITUDES]; //array of wind vectors
	
	//sets the wind at each altitude and sends the force to Force Accumuator
	void GenerateWinds() {
		FVector WindVector; //wind vector inserted into the array
		for (int i = 0; i < g_avDirections->Size(); i++) {
			WindVector.X = FMath::FRandRange(-1, 1);
			WindVector.Y = FMath::FRandRange(-1, 1);
			while (WindVector.Size() > 1) {
				WindVector.X = FMath::FRandRange(-1, 1);
				WindVector.Y = FMath::FRandRange(-1, 1);
			}
			g_avDirections[i].Set(WindVector.X, WindVector.Y, 0);
		}
	}
	//gets the wind at specific altitude
	FVector GetWindDirectionAtAltitude(meters m) {
		int FirstIndex = fmod(m / 100, NUM_ALTITUDES);
		int SecondIndex = fmod(FirstIndex + 1, NUM_ALTITUDES);
		float FirstPercent = fmod(m, 100) / 100;
		float SecondPercent = 1 - FirstPercent;
		FVector firstWind = g_avDirections[FirstIndex];
		FVector secondWind = g_avDirections[SecondIndex];
		FVector WindDirection = (FirstPercent * firstWind) + (SecondPercent * secondWind);
		return WindDirection;
	}
	Force GetWindForceAtAltitude(meters m) {
		FVector WindForce = GetWindDirectionAtAltitude(m) * WIND_FORCE_MULTIPLIER;
		Force f;
		f.m_vector = WindForce;
		f.m_eForceType = Force::WIND;
		return f;
		
	}
}