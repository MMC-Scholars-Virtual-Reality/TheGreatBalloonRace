// This software is under partial ownership by The Ohio State University, for it is a product of student employees. For official policy, see https://tco.osu.edu/sites/default/files/pdfs/IP-Policy.pdf or contact The Ohio State University Office of Legal Affairs.

#pragma once

#include "CoreMinimal.h"
#include "AMoveLinear/AMoveLinear.h"
#include "PropellerController.generated.h"

class PropellerEngine;

UCLASS()
class THEGREATBALLOONRACE_API APropellerController : public AMoveLinear {
	GENERATED_BODY()
	
	public:
		APropellerController();

		void DefaultThink() override;

		PropellerEngine* m_pEngine;
};