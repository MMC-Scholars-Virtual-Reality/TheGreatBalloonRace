// Fill out your copyright notice in the Description page of Project Settings.

#include "TheGreatBalloonRaceGameModeBase.h"

void ATheGreatBalloonRaceGameModeBase::UpdateTimeLimit() {
	m_iTimeLimit = m_iTimePerRing * m_aPathRings.Num();
}

int ATheGreatBalloonRaceGameModeBase::getNumPathRings() {
	return m_aPathRings.Num();
}


