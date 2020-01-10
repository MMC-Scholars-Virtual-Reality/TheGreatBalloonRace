// This software is under partial ownership by The Ohio State University, for it is a product of student employees. For official policy, see https://tco.osu.edu/sites/default/files/pdfs/IP-Policy.pdf or contact The Ohio State University Office of Legal Affairs.

#include "BalloonController.h"
#include "ABasePawn/ABasePawn.h"
//#include "System/NLogger.h"

ABalloonController::ABalloonController() {
}

void ABalloonController::OnButtonsChanged() {
	if (m_iButtonsPressed & IN_BY) { // reset location	
		g_pBasePawn->TeleportPlayer(g_pBasePawn->getInitialLocation(), g_pBasePawn->getInitialRotation());
		g_pBasePawn->TeleportPlayer(g_pBasePawn->getInitialLocation(), g_pBasePawn->getInitialRotation());
	}
	Super::OnButtonsChanged();
}
