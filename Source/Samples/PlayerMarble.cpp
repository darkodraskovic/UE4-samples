// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerMarble.h"
#include "GameFramework/PlayerInput.h"
#include "Components/InputComponent.h"

APlayerMarble::APlayerMarble()
{
    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));

    SpringArm->bDoCollisionTest = false;
    SpringArm->SetUsingAbsoluteRotation(true);
    SpringArm->SetRelativeRotation(FRotator(-45.0f, 0.0f, 0.0f));
    SpringArm->TargetArmLength = 100.0f;
    SpringArm->bEnableCameraLag = false;
    SpringArm->CameraLagSpeed = 5.0f;

    SpringArm->SetupAttachment(MarbleMesh);

    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera->bUsePawnControlRotation = false;
    Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);

    Magnetized = false;
}

static void InitializeDefaultPawnInputBindings()
{
	static bool bindingsAdded = false;
    if (bindingsAdded == false)
    {
        bindingsAdded = true;

        UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("Marble_MoveX", EKeys::W, 1.f));
        UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("Marble_MoveX", EKeys::S, -1.f));
        UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("Marble_MoveX", EKeys::Up, 1.f));
        UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("Marble_MoveX", EKeys::Down, -1.f));
        UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("Marble_MoveY", EKeys::A, -1.f));
        UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("Marble_MoveY", EKeys::D, 1.f));
        UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("Marble_MoveY", EKeys::Left, -1.f));
        UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("Marble_MoveY", EKeys::Right, 1.f));

        UPlayerInput::AddEngineDefinedActionMapping(FInputActionKeyMapping("Marble_Jump", EKeys::SpaceBar));
        UPlayerInput::AddEngineDefinedActionMapping(FInputActionKeyMapping("Marble_Dash", EKeys::LeftShift));
    }
}

void APlayerMarble::SetupPlayerInputComponent(UInputComponent* playerInputComponent)
{
    check(playerInputComponent != nullptr);

    Super::SetupPlayerInputComponent(playerInputComponent);

    InitializeDefaultPawnInputBindings();

    playerInputComponent->BindAxis("Marble_MoveX", this, &APlayerMarble::MoveX);
    playerInputComponent->BindAxis("Marble_MoveY", this, &APlayerMarble::MoveY);

    playerInputComponent->BindAction("Marble_Jump", EInputEvent::IE_Pressed, this, &APlayerMarble::Jump);
    playerInputComponent->BindAction("Marble_Dash", EInputEvent::IE_Pressed, this, &APlayerMarble::Dash);
}

void APlayerMarble::MoveX(float value) 
{
    InputX = value;
}

void APlayerMarble::MoveY(float value) 
{
    InputY = value;
}	

void APlayerMarble::Jump() 
{
    UE_LOG(LogTemp, Warning, TEXT("Jump") );
}

void APlayerMarble::Dash() 
{
    UE_LOG(LogTemp, Warning, TEXT("Dash") );
}	

void APlayerMarble::Tick(float deltaSeconds)
{
    Super::Tick(deltaSeconds);

    MarbleMesh->AddForce(FVector(InputX, InputY, 0.0f) * ControllerForce * MarbleMesh->GetMass());
}