// Fill out your copyright notice in the Description page of Project Settings.


#include "Rotor.h"


// Sets default values
ARotor::ARotor() : PitchValue(0.f), YawValue(0.f), RollValue(0.f)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("My Super Mesh"));
}

// Called when the game starts or when spawned
void ARotor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARotor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FRotator NewRotation = FRotator(PitchValue, YawValue, RollValue);
	FQuat QuatRotation = FQuat(NewRotation);
	AddActorLocalRotation(QuatRotation, false, 0, ETeleportType::None);

	// Causes a bug for the pitch value. The pitch value stops updating at 90 degrees
	// solution by ue4 user nutellis https://answers.unrealengine.com/questions/591752/pitch-rotation-stucks-at-90-90-c.html
	// FRotator NewRotation = GetActorRotation().Add(PitchValue, YawValue, RollValue);
	// SetActorRotation(NewRotation);	
}

