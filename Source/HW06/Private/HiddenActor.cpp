#include "HiddenActor.h"

AHiddenActor::AHiddenActor()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	PrimaryActorTick.bCanEverTick = true;

}

void AHiddenActor::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorld()->GetTimerManager().SetTimer(HideTimerHandle, this, &AHiddenActor::ToggleHideActor, 5.0f, true);
}

void AHiddenActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bHidden)
	{
		return;
	}
}

void AHiddenActor::ToggleHideActor()
{
	if (bHidden)
	{
		SetActorHiddenInGame(false);
		SetActorEnableCollision(true);
		bHidden = false;
	}
	else
	{
		SetActorHiddenInGame(true);
		SetActorEnableCollision(false);
		bHidden = true;
	}
}
