// Fill out your copyright notice in the Description page of Project Settings.

#include "PropellerController.h"
#include "PropellerEngine.h"

APropellerController::APropellerController() {
	m_pEngine = NULL;
}

void APropellerController::DefaultThink() {
	Super::DefaultThink();
	if (m_pEngine)
		m_pEngine->setThrottle(GetLerpPosition(), EThrottle::THROTTLE_MAIN);
}

