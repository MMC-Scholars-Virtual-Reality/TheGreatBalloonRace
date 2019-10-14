// This software is under partial ownership by The Ohio State University, for it is a product of student employees. For official policy, see https://tco.osu.edu/sites/default/files/pdfs/IP-Policy.pdf or contact The Ohio State University Office of Legal Affairs.

#include "PathCreator.h"
#include "System/NLogger.h"

#define SPLINE_MESH "StaticMesh'/Game/Models/Spline.Spline'"
#define RING_MESH "StaticMesh'/Game/Models/Ring.Ring'"
#define MESH_AXIS ESplineMeshAxis::Type(ESplineMeshAxis::Z)

APathCreator::APathCreator() {
	m_pSpline = CreateDefaultSubobject<USplineComponent>("spline");
	RootComponent = m_pSpline;

	m_pSplineMesh = FindMesh(SPLINE_MESH);
	m_pRingMesh = FindMesh(RING_MESH);
	m_pSplineForward = MESH_AXIS;

	m_uScore = 0;
}

void APathCreator::OnConstruction(const FTransform& Transform) {
	int32 numSplinePoints = m_pSpline->GetNumberOfSplinePoints();

	for (int32 i = 0; i < numSplinePoints - 1; i++) {
		
		// spline mesh
		
		USplineMeshComponent* pSplineMeshComponent = NewObject<USplineMeshComponent>(this, USplineMeshComponent::StaticClass());
		pSplineMeshComponent->RegisterComponentWithWorld(GetWorld());
		pSplineMeshComponent->CreationMethod = EComponentCreationMethod::UserConstructionScript;
		
		pSplineMeshComponent->SetStaticMesh(m_pSplineMesh);
		pSplineMeshComponent->SetMobility(EComponentMobility::Movable);
		pSplineMeshComponent->SetForwardAxis(m_pSplineForward);
		
		pSplineMeshComponent->AttachToComponent(m_pSpline, FAttachmentTransformRules::KeepRelativeTransform);

		FVector sLoc, sTan, eLoc, eTan;
		ESplineCoordinateSpace::Type coordinateSpace = ESplineCoordinateSpace::Local;

		m_pSpline->GetLocationAndTangentAtSplinePoint(i, sLoc, sTan, coordinateSpace);
		m_pSpline->GetLocationAndTangentAtSplinePoint(i + 1, eLoc, eTan, coordinateSpace);

		pSplineMeshComponent->SetStartAndEnd(sLoc, sTan, eLoc, eTan);

		// ring mesh

		UStaticMeshComponent* pRingMeshComponent = NewObject<UStaticMeshComponent>(this, UStaticMeshComponent::StaticClass());
		pRingMeshComponent->RegisterComponentWithWorld(GetWorld());
		pRingMeshComponent->CreationMethod = EComponentCreationMethod::UserConstructionScript;

		pRingMeshComponent->SetStaticMesh(m_pRingMesh);

		pRingMeshComponent->SetWorldLocation(eLoc);
		pRingMeshComponent->AttachToComponent(pSplineMeshComponent, FAttachmentTransformRules::KeepRelativeTransform);
		// TODO refined location, rotation and scale
	}

}

