
#include "BurnerController.h"

ABurnerController::ABurnerController() {
	m_pBurner = NULL;
}
void ABurnerController::DefaultThink() {
	//Super::DefaultThink();
	float lrp = -fmodf(g_pGlobals->curtime, 1.0f);
	//Msg("%f", lrp);
	SetLerpPosition(lrp);

	if (m_pBurner)
		m_pBurner->SetThrottleLevel(GetLerpPosition());
}



