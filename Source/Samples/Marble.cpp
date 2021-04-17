// Fill out your copyright notice in the Description page of Project Settings.


#include "Marble.h"


// Sets default values
AMarble::AMarble()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MarbleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MarbleMesh"));
	MarbleMesh->SetSimulatePhysics(true);

	SetRootComponent(MarbleMesh);
}

// Called when the game starts or when spawned
void AMarble::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMarble::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMarble::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
