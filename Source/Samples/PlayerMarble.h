// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Marble.h"
#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "PlayerMarble.generated.h"
/**
 * 
 */
UCLASS()
class SAMPLES_API APlayerMarble : public AMarble
{
	GENERATED_BODY()
	
public:
	APlayerMarble();

	UPROPERTY(VisibleAnywhere, BlueprintReadonly, Category = Marble)
	USpringArmComponent* SpringArm = nullptr;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadonly, Category = Marble)
	UCameraComponent* Camera = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadonly, Category = Marble)
	float ControllerForce = 250.0f;

	UPROPERTY(EditAnywhere, BlueprintReadonly, Category = Marble)
	float JumpForce = 50.0f;

	UPROPERTY(EditAnywhere, BlueprintReadonly, Category = Marble)
	float DashForce = 150.0f;

	UPROPERTY(EditAnywhere, BlueprintReadonly, Category = Marble)
	float MaxSpeed = 150.0f;

protected:

	virtual void Tick(float deltaSeconds) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* playerInputComponent) override;
	
private:
	void MoveX(float value);
	void MoveY(float value);
	void Jump();
	void Dash();

	float InputX = 0.0f;
	float InputY = 0.0f;
	float DashTimer = 0.0f;

	friend class AMarbleDebugHUD;
};