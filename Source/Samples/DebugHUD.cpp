// Fill out your copyright notice in the Description page of Project Settings.


#include "DebugHUD.h"
#include "Engine/Canvas.h"
#include "CanvasItem.h"

ADebugHUD::ADebugHUD() 
{
    static ConstructorHelpers::FObjectFinder<UFont> Font(TEXT("/Game/Fonts/Debug.Debug"));

    DebugFont = Font.Object;
};

	
void ADebugHUD::DrawHUD() 
{
    Super::DrawHUD();
    X = Y = 50.0f; 
}

void ADebugHUD::AddStatistic(const TCHAR* title, const FText& value) 
{
    RenderStatistic(title, value);
}

void ADebugHUD::AddStatistic(const TCHAR* title, float value) 
{
    RenderStatistic(title, FText::AsNumber(value));
}

void ADebugHUD::AddStatistic(const TCHAR* title, int value) 
{
    RenderStatistic(title, FText::AsNumber(value));
}

void ADebugHUD::AddStatistic(const TCHAR* title, bool value) 
{
    RenderStatistic(title, ToText(value), (value == true) ? FLinearColor::Green : FLinearColor::Red);
}

FText ADebugHUD::ToText(const TCHAR* text) 
{
    return FText::FromString(text);
}

FText ADebugHUD::ToText(bool value) 
{
    return ToText(value == true ? TEXT("true") : TEXT("false"));
}

void ADebugHUD::RenderStatistic(const TCHAR* title, const FText& value, const FLinearColor& color) 
{
    FCanvasTextItem item0(FVector2D(X,Y), ToText(title), DebugFont, FLinearColor::White);
    item0.EnableShadow(FLinearColor::Black);
    Canvas->DrawItem(item0);
    FCanvasTextItem item1(FVector2D(X+HorizontalOffset,Y), value, DebugFont, color);
    item1.EnableShadow(FLinearColor::Black);
    Canvas->DrawItem(item1);
    Y += LineHeight;
}