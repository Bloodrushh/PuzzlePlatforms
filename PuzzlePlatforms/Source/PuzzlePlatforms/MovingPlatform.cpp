// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"


AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;

	SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::AddActiveTrigger()
{
	ActiveTriggers++;
}

void AMovingPlatform::RemoveActiveTrigger()
{
	if (ActiveTriggers > 0)
	{
		ActiveTriggers--;
	}	
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())
	{
		SetReplicates(true);
		SetReplicateMovement(true);
	}

	GlobalStartLocation = GetActorLocation();
	GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation); // converts local position to global
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//(true ? false : 1, 2);

	if (ActiveTriggers > 0)
	{
		if (HasAuthority())
		{
			FVector Location = GetActorLocation();

			float JourneyLenght = (GlobalTargetLocation - GlobalStartLocation).Size();
			float JourneyTravelled = (Location - GlobalStartLocation).Size();

			if (JourneyTravelled >= JourneyLenght)
			{
				FVector Swap = GlobalStartLocation;
				GlobalStartLocation = GlobalTargetLocation;
				GlobalTargetLocation = Swap;
			}

			FVector Direction = (GlobalTargetLocation - GlobalStartLocation).GetSafeNormal();

			Location += MovingSpeed * DeltaTime * Direction;
			SetActorLocation(Location);
		}
	}		
}

