// Copyright Epic Games, Inc. All Rights Reserved.


#include "SamplesGameModeBase.h"
#include "MarbleDebugHUD.h"

ASamplesGameModeBase::ASamplesGameModeBase() 
{
    PrimaryActorTick.bCanEverTick = true;
    HUDClass = AMarbleDebugHUD::StaticClass();
}