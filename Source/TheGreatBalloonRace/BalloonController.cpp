// This software is under partial ownership by The Ohio State University, for it is a product of student employees. For official policy, see https://tco.osu.edu/sites/default/files/pdfs/IP-Policy.pdf or contact The Ohio State University Office of Legal Affairs.

#include "BalloonController.h"
#include "System/NLogger.h"

ABalloonController::ABalloonController() {
}

void ABalloonController::OnButtonsChanged() {
	if (m_iButtonsPressed & IN_BY) {
		Msg("Test of BY buttons pressed");
	}
	else if (m_iButtonsPressed) {
		NLogger::Warning("buttons is %d", m_iButtonsPressed);
		NLogger::Warning("there's nothing to see here.");
	}

	Super::OnButtonsChanged();
}
