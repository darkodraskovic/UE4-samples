// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerSphere.h"
#include "Marble.h"
#include "MagneticField.generated.h"

/**
 * 
 */
UCLASS()
class SAMPLES_API AMagneticField : public ATriggerSphere
{
	GENERATED_BODY()

public:

	AMagneticField();

protected:

	virtual void PostInitializeComponents() override;
	virtual void NotifyActorBeginOverlap(AActor* other) override;
	virtual void NotifyActorEndOverlap(AActor* other) override;
	
private:
	UPROPERTY(Transient)
		TArray<AMarble*> Marbles;
};
