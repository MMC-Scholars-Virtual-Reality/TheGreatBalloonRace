// This software is under partial ownership by The Ohio State University, for it is a product of student employees. For official policy, see https://tco.osu.edu/sites/default/files/pdfs/IP-Policy.pdf or contact The Ohio State University Office of Legal Affairs.

#include "PropellerController.h"
#include "PropellerEngine.h"
#include "System/NLogger.h"

APropellerController::APropellerController() {
	m_pEngine = NULL;
}

void APropellerController::DefaultThink() {
	Super::DefaultThink();
//	Msg("PropellerController lerp position is %f", GetLerpPosition());
	if (m_pEngine)
		m_pEngine->setThrottle(GetLerpPosition(), EThrottle::THROTTLE_MAIN);
}

