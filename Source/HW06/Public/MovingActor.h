#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingActor.generated.h"

UCLASS()
class HW06_API AMovingActor : public AActor
{
	GENERATED_BODY()
	
public:
	AMovingActor();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MoveingActor|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MoveingActor|Components")
	UStaticMeshComponent* StaticMeshComp;

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MoveingActor|Properties")
	FVector Velocity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MoveingActor|Properties")
	FVector StartLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MoveingActor|Properties")
	float MaxRange;
	
	bool bMovingForward = true;

public:
	virtual void Tick(float DeltaTime) override;

};
