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

void AMarble::ResetLocation() const
{
	MarbleMesh->SetWorldLocation(InitalLocation + FVector(0.f, 0.f, 150.f));
	MarbleMesh->SetPhysicsLinearVelocity(FVector::ZeroVector);
	MarbleMesh->SetPhysicsAngularVelocity(FVector::ZeroVector);
}

// Called when the game starts or when spawned
void AMarble::BeginPlay()
{
	Super::BeginPlay();
	
	InitalLocation = MarbleMesh->GetComponentLocation();

	MarbleMesh->SetLinearDamping(.5f);
	MarbleMesh->SetAngularDamping(.5f);
}

// Called every frame
void AMarble::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	InContact = false;
}

// Called to bind functionality to input
void AMarble::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMarble::NotifyHit(UPrimitiveComponent* myComp, AActor* otherActor, UPrimitiveComponent* otherComp, bool selfMoved, FVector hitLocation, FVector hitNormal, FVector normalImpulse, const FHitResult& hitResult)
{
	Super::NotifyHit(myComp, otherActor, otherComp, selfMoved, hitLocation, hitNormal, normalImpulse, hitResult);

	InContact = true;
}
