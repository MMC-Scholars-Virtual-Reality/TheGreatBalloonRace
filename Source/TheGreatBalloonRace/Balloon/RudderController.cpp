#include "RudderController.h"

//inherit from ABaseLinear
ARudderController::ARudderController() {
	m_rudderController= CreateDefaultSubobject<UStaticMeshComponent>("m_RudderController");
	pController = NULL;
}
void think(ABaseController* pController) {
	ARudderController rudder1;
	rudder1.SetPositionFromController(pController);

}