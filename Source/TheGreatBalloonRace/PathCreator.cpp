// This software is under partial ownership by The Ohio State University, for it is a product of student employees. For official policy, see https://tco.osu.edu/sites/default/files/pdfs/IP-Policy.pdf or contact The Ohio State University Office of Legal Affairs.

#include "PathCreator.h"
#include "Components/SplineMeshComponent.h"
#include "System/NLogger.h"

#define MESH "StaticMesh'/Game/Meshes/cubeTest.cubeTest'"
#define MESH_AXIS ESplineMeshAxis::Type(ESplineMeshAxis::X)

APathCreator::APathCreator() {
	m_pSpline = CreateDefaultSubobject<USplineComponent>("spline");

	RootComponent = m_pSpline;

	int32 numPoints = m_pSpline->GetNumberOfSplinePoints();
	Msg("numPoints is %d!", numPoints);

	for (int i = 0; i < numPoints - 1; i++) { // each segment consists of a start and end, so subtract one from the total
		//USplineMeshComponent* pSplineMesh = NewObject<USplineMeshComponent>(USplineMeshComponent::StaticClass(), i);
		USplineMeshComponent* pSplineMesh = CreateDefaultSubobject<USplineMeshComponent>("spline mesh " + i);
		pSplineMesh->SetMobility(EComponentMobility::Movable);
		//		pSplineMesh->AttachToComponent(m_pSpline, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
		pSplineMesh->SetStaticMesh(FindMesh(MESH));
		pSplineMesh->SetForwardAxis(MESH_AXIS);

		ESplineCoordinateSpace::Type coordSpace = ESplineCoordinateSpace::Local;

		FVector sLoc = m_pSpline->GetLocationAtSplinePoint(i, coordSpace);
		FVector sTan = m_pSpline->GetTangentAtSplinePoint(i, coordSpace);

		FVector eLoc = m_pSpline->GetLocationAtSplinePoint(i + 1, coordSpace);
		FVector eTan = m_pSpline->GetTangentAtSplinePoint(i + 1, coordSpace);

		pSplineMesh->SetStartAndEnd(sLoc, sTan, eLoc, eTan);
	}

}


