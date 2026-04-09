#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HiddenActor.generated.h"

UCLASS()
class HW06_API AHiddenActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AHiddenActor();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MoveingActor|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MoveingActor|Components")
	UStaticMeshComponent* StaticMeshComp;

protected:
	virtual void BeginPlay() override;
	UFUNCTION()
	virtual void ToggleHideActor();


public:	
	virtual void Tick(float DeltaTime) override;

	FTimerHandle HideTimerHandle;
	bool bHidden;

};
