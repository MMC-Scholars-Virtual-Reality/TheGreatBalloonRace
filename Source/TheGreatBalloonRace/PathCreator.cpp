// This software is under partial ownership by The Ohio State University, for it is a product of student employees. For official policy, see https://tco.osu.edu/sites/default/files/pdfs/IP-Policy.pdf or contact The Ohio State University Office of Legal Affairs.

#include "PathCreator.h"
#include "Components/SplineMeshComponent.h"
#include "System/NLogger.h"

#define MESH "StaticMesh'/Game/Models/cubeTest.cubeTest'"
#define MESH_AXIS ESplineMeshAxis::Type(ESplineMeshAxis::X)

APathCreator::APathCreator() {
	m_pSpline = CreateDefaultSubobject<USplineComponent>("spline");
	RootComponent = m_pSpline;

	int32 numPoints = m_pSpline->GetNumberOfSplinePoints();
	for (int i = 0; i < numPoints - 1; i++) { // each segment consists of a start and end, so subtract one from the total
		USplineMeshComponent* pSplineMesh = NewObject<USplineMeshComponent>(this, USplineMeshComponent::StaticClass(), L"spline mesh " + i);

		pSplineMesh->SetMobility(EComponentMobility::Movable);

		pSplineMesh->SetStaticMesh(FindMesh(MESH));
		pSplineMesh->SetForwardAxis(MESH_AXIS);

		FVector sLoc, sTan, eLoc, eTan;
		ESplineCoordinateSpace::Type coordinateSpace = ESplineCoordinateSpace::Local;

		m_pSpline->GetLocationAndTangentAtSplinePoint(i, sLoc, sTan, coordinateSpace);
		m_pSpline->GetLocationAndTangentAtSplinePoint(i+1, eLoc, eTan, coordinateSpace);

		pSplineMesh->SetStartAndEnd(sLoc, sTan, eLoc, eTan);
	}

}


