// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "DebugHUD.h"
#include "CoreMinimal.h"
#include "MarbleDebugHUD.generated.h"

/**
 * 
 */
UCLASS()
class AMarbleDebugHUD : public ADebugHUD
{
	GENERATED_BODY()

	virtual void DrawHUD() override;
};
