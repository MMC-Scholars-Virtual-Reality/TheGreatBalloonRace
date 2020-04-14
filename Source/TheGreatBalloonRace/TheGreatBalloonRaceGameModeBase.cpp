// Fill out your copyright notice in the Description page of Project Settings.

#include "TheGreatBalloonRaceGameModeBase.h"

void ATheGreatBalloonRaceGameModeBase::UpdateTimeLimit() {
	m_iTimeLimit = m_iTimePerRing * m_aPathRings.Num();
}

void ATheGreatBalloonRaceGameModeBase::EndGame(bool playerWon) {
	if (playerWon) {
		//Victory Screen
		Msg("You win!");
	}
	else {
		//Defeat Screen
		Msg("You lose!");
	}
}


