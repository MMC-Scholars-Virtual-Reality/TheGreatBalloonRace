#include "RudderController.h"


//inherit from ABaseLinear
ARudderController::ARudderController() {
	m_pEngine = NULL;
}
//tell engine how strong throttle is
void ARudderController::DefaultThink() {
	//figure out which propeller they want to use, add energy to the propeller based on how high the throttle is set
	//m_pEngine->setThrottle(GetLerpPosition(), THROTTLE_RUDDER);

	
}