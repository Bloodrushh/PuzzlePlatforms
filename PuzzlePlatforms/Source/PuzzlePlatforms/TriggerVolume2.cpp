// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerVolume2.h"
//#include "DrawDebugHelpers.h"
//#include "MeshDrawShaderBindings.h"
//#include "ShaderCore.h"
#include "Components/BoxComponent.h"


// Sets default values
ATriggerVolume2::ATriggerVolume2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TriggerVolume = CreateDefaultSubobject<UBoxComponent>(FName("TriggerVolume"));
	//if (!ensure(TriggerVolume != nullptr)) return;
	RootComponent = TriggerVolume;

}

// Called when the game starts or when spawned
void ATriggerVolume2::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATriggerVolume2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

