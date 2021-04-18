// Fill out your copyright notice in the Description page of Project Settings.


#include "MagneticField.h"
#include "Components/SphereComponent.h"
#include "Components/BillboardComponent.h"

AMagneticField::AMagneticField()
{
	SetActorHiddenInGame(false);
}

void AMagneticField::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	GetCollisionComponent()->SetHiddenInGame(true);

#if	WITH_EDITORONLY_DATA
	GetSpriteComponent()->SetHiddenInGame(true);
#endif
}

void AMagneticField::NotifyActorBeginOverlap(AActor* other)
{
	Super::NotifyActorBeginOverlap(other);

	AMarble* marble = Cast<AMarble>(other);
	if (marble && marble->Magnetized) Marbles.AddUnique(marble);
}

void AMagneticField::NotifyActorEndOverlap(AActor* other)
{
	Super::NotifyActorEndOverlap(other);

	AMarble* marble = Cast<AMarble>(other);
	if (marble) Marbles.Remove(marble);
}
