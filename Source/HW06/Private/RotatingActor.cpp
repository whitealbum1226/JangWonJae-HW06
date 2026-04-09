#include "RotatingActor.h"

ARotatingActor::ARotatingActor()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	PrimaryActorTick.bCanEverTick = true;
	RotationSpeed = FRotator(0.f, 100.f, 0.f);
	MoveSpeed = FVector(0.f, 0.f, 10.f);
	MaxRange = 10.f;
}

void ARotatingActor::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
	
}

void ARotatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	AddActorLocalRotation(RotationSpeed * DeltaTime);

	FVector Move = MoveSpeed * DeltaTime;

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

