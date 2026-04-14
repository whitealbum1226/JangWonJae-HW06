#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingActor.generated.h"

UCLASS()
class HW06_API ARotatingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ARotatingActor();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MoveingActor|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MoveingActor|Components")
	UStaticMeshComponent* StaticMeshComp;

	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "MoveingActor|Properties")
	FRotator RotationSpeed;
	FVector StartLocation;
	FVector MoveSpeed;
	bool bMovingForward = true;
	float MaxRange;

public:	
	virtual void Tick(float DeltaTime) override;

};
