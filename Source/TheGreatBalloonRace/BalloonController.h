// This software is under partial ownership by The Ohio State University, for it is a product of student employees. For official policy, see https://tco.osu.edu/sites/default/files/pdfs/IP-Policy.pdf or contact The Ohio State University Office of Legal Affairs.

#pragma once

#include "CoreMinimal.h"
#include "VRBase/ABaseController/ABaseController.h"
#include "BalloonController.generated.h"

UCLASS()
class THEGREATBALLOONRACE_API ABalloonController : public ABaseController {
	GENERATED_BODY()

	public:
		ABalloonController();

		virtual void OnButtonsChanged() override;
};
