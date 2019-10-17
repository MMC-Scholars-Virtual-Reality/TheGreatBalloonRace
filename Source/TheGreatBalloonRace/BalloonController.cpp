// This software is under partial ownership by The Ohio State University, for it is a product of student employees. For official policy, see https://tco.osu.edu/sites/default/files/pdfs/IP-Policy.pdf or contact The Ohio State University Office of Legal Affairs.

#include "BalloonController.h"
#include "ABasePawn/ABasePawn.h"
#include "System/NLogger.h"

ABalloonController::ABalloonController() {
}

void ABalloonController::OnButtonsChanged() {
	if (m_iButtonsPressed & IN_BY) { // reset teleportation
		// for some reason it must reset twice to reset correctly - fix this issue later
		g_pBasePawn->TeleportPlayer(g_pBasePawn->getInitialLocation(), g_pBasePawn->getInitialRotation());
		g_pBasePawn->TeleportPlayer(g_pBasePawn->getInitialLocation(), g_pBasePawn->getInitialRotation());
	}
//	else if (m_iButtonsPressed) {
//		NLogger::Warning("buttons is %d", m_iButtonsPressed);
//	}

	Super::OnButtonsChanged();
}
