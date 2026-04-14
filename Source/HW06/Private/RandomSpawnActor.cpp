#include "RandomSpawnActor.h"
#include "MovingActor.h"
#include "RotatingActor.h"

ARandomSpawnActor::ARandomSpawnActor()
{
	PrimaryActorTick.bCanEverTick = false;

}

void ARandomSpawnActor::BeginPlay()
{
    Super::BeginPlay();

    // Å¬·¡½º Ã¼Å©
    if (!MovingActorClass || !RotatingActorClass)
    {
        return;
    }

    for (int i = 0; i < 5; ++i)
    {
        // ·£´ý À§Ä¡
        FVector SpawnLocation;
        SpawnLocation.X = i * 500.0f;
        SpawnLocation.Y = FMath::RandRange(-1000.0f, 1000.0f);
        SpawnLocation.Z = 100.0f;

        // ÀÌµ¿ ÇÃ·§Æû »ý¼º
        AMovingActor* Moving = GetWorld()->SpawnActor<AMovingActor>(
            MovingActorClass,
            SpawnLocation,
            FRotator::ZeroRotator
        );

        if (Moving)
        {
            float Speed = FMath::RandRange(100.0f, 300.0f);

            int32 Dir = FMath::RandRange(0, 1);

            if (Dir == 0)
            {
                Moving->Velocity = FVector(Speed, 0, 0);
            }
            else
            {
                Moving->Velocity = FVector(0, Speed, 0);
            }

            Moving->MaxRange = FMath::RandRange(200.0f, 500.0f);
        }

        // È¸Àü ÇÃ·§Æû »ý¼º
        FVector RotLocation;
        RotLocation.X = SpawnLocation.X + 500.0f;
        RotLocation.Y = FMath::RandRange(-1500.0f, 1500.0f);
        RotLocation.Z = 300.0f;

        ARotatingActor* Rot = GetWorld()->SpawnActor<ARotatingActor>(
            RotatingActorClass,
            RotLocation,
            FRotator::ZeroRotator
        );

        if (Rot)
        {
            Rot->RotationSpeed = FRotator(
                0.0f,
                0.0f,
                FMath::RandRange(30.0f, 120.0f)
            );
        }
    }
}

void ARandomSpawnActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

