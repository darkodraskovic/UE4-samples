// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "DebugHUD.generated.h"

/**
 * 
 */
UCLASS()
class ADebugHUD : public AHUD
{
	GENERATED_BODY()

protected:

	ADebugHUD();
	
	virtual void DrawHUD() override;

	void AddStatistic(const TCHAR* title, const FText& value);
	void AddStatistic(const TCHAR* title, float value);
	void AddStatistic(const TCHAR* title, int value);
	void AddStatistic(const TCHAR* title, bool value);

	float HorizontalOffset = 150.0f;

private:

	FText ToText(const TCHAR* text);
	FText ToText(bool value);

	void RenderStatistic(const TCHAR* title, const FText& value, const FLinearColor& color = FLinearColor::White);

	UPROPERTY(Transient)
	UFont* DebugFont = nullptr;

	// Current coordinates
	float X = 50.0f;
	float Y = 50.0f;

	float LineHeight = 16.0f;

	friend class ADebugHUD;
};
