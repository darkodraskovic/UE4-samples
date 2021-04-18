// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Marble.generated.h"

UCLASS()
class SAMPLES_API AMarble : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMarble();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Marble);
		class UStaticMeshComponent* MarbleMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Marble);
		float Magnetized = 1.0f;

	UFUNCTION(BlueprintCallable, Category = "Marble")
		void ResetLocation() const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void NotifyHit(
		UPrimitiveComponent* myComp, AActor* otherActor, UPrimitiveComponent* otherComp, bool selfMoved, FVector hitLocation, FVector hitNormal, FVector normalImpulse, const FHitResult& hitResult);

	// Set to false in Tick(), set to true in NotifyHit() to see if ball is in air; do not query between calls to Tick() and NotifyHit()!
	bool InContact = false;

private:
	FVector InitalLocation = FVector::ZeroVector;

	friend class ADebugHUD;
};