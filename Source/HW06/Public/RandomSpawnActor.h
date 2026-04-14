#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RandomSpawnActor.generated.h"

class AMovingActor;
class ARotatingActor;

UCLASS()
class HW06_API ARandomSpawnActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ARandomSpawnActor();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawn")
	UClass* MovingActorClass;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawn")
	UClass* RotatingActorClass;

};
