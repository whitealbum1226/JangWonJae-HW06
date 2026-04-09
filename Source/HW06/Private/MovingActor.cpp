#include "MovingActor.h"

AMovingActor::AMovingActor()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	PrimaryActorTick.bCanEverTick = true;
	Velocity = FVector(100.f, 0.f, 0.f);
	MaxRange = 300.f;

}

void AMovingActor::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
}

void AMovingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector Move = Velocity * DeltaTime;

	if (bMovingForward)
	{
		AddActorWorldOffset(Move);
	}
	else
	{
		AddActorWorldOffset(-Move);
	}

	float Distance = FVector::Dist(StartLocation, GetActorLocation());

	if (Distance >= MaxRange)
	{
		bMovingForward = !bMovingForward;
	}
}


