// Fill out your copyright notice in the Description page of Project Settings.

#include "PropellerController.h"
#include "PropellerEngine.h"

APropellerController::APropellerController() {
	m_pPropellerEngine = NULL;
}

void APropellerController::DefaultThink() {
	Super::DefaultThink();
	if (m_pPropellerEngine)
		m_pPropellerEngine->setThrottle(GetLerpPosition(), EThrottle::THROTTLE_MAIN);
}

