// Fill out your copyright notice in the Description page of Project Settings.


#include "MarbleDebugHUD.h"
#include "PlayerMarble.h"

void AMarbleDebugHUD::DrawHUD() 
{
    Super::DrawHUD();

    APlayerMarble* playerMarble = Cast<APlayerMarble>(GetOwningPawn());

    if (playerMarble != nullptr) {
        AddStatistic(TEXT("In contact"), playerMarble->InContact);
        AddStatistic(TEXT("Speed"), playerMarble->GetVelocity().Size() / 100.f);
        AddStatistic(TEXT("Dash timer"), playerMarble->DashTimer);
        AddStatistic(TEXT("Input X"), playerMarble->InputX);
        AddStatistic(TEXT("Input Y"), playerMarble->InputY);
    }
}


