// Fill out your copyright notice in the Description page of Project Settings.


#include "InputMover.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AInputMover::AInputMover()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
    // Set this pawn to be controlled by the lowest-numbered player
    AutoPossessPlayer = EAutoReceiveInput::Player0;

    // Root component
    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

    StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    StaticMesh->SetupAttachment(RootComponent);

    UCameraComponent* Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera->SetupAttachment(RootComponent);
    Camera->SetRelativeLocation(FVector(-250.0f, 0.0f, 250.0f));
    Camera->SetRelativeRotation(FRotator(-45.0f, 0.0f, 0.0f));
}

// Called when the game starts or when spawned
void AInputMover::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInputMover::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    float Scale = StaticMesh->GetComponentScale().X;
    if (bGrowing)
    {
        Scale += DeltaTime;
    }
    else
    {
        Scale -= DeltaTime * 0.5f;
    }
    Scale = FMath::Clamp(Scale, 1.0f, 2.0f);
    StaticMesh->SetWorldScale3D(FVector(Scale));
    
    if (!Velocity.IsZero())
    {
        FVector Destination = GetActorLocation() + Velocity * DeltaTime;
        SetActorLocation(Destination);
    }
}

// Called to bind functionality to input
void AInputMover::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAction("Grow", IE_Pressed, this, &AInputMover::Grow);
    PlayerInputComponent->BindAction("Grow", IE_Released, this, &AInputMover::Shrink);

    PlayerInputComponent->BindAxis("MoveX", this, &AInputMover::MoveXAxis);
    PlayerInputComponent->BindAxis("MoveY", this, &AInputMover::MoveYAxis);
}

void AInputMover::MoveXAxis(float AxisValue)
{
    // 100 units per second forward or backward
    Velocity.X = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 100.0f;
}

void AInputMover::MoveYAxis(float AxisValue)
{
    // 100 units per second right or left
    Velocity.Y = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 100.0f;
}

void AInputMover::Grow()
{
    UE_LOG(LogTemp, Warning, TEXT("Grow") );
    bGrowing = true;
}

void AInputMover::Shrink()
{
    UE_LOG(LogTemp, Warning, TEXT("Shrink") );
    bGrowing = false;
}