#include "RudderController.h"

//inherit from ABaseLinear
ARudderController::ARudderController() {
	m_pEngine = NULL;
}

//tell engine how strong throttle is
void ARudderController::DefaultThink() {
	Super::DefaultThink();

	if (m_pEngine)
		m_pEngine->setThrottle(GetLerpPosition(), EThrottle::THROTTLE_RUDDER);
}