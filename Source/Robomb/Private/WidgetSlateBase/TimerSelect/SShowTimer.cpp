// Fill out your copyright notice in the Description page of Project Settings.


#include "SShowTimer.h"
#include "SlateOptMacros.h"
#include "SBox.h"
#include "STextBlock.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SShowTimer::Construct(const FArguments& InArgs)
{
	ChildSlot
	[
		// Populate the widget
		SNew(SBox)
		.HeightOverride(50.0)
		.WidthOverride(70.0)
		[
			SAssignNew(ShowTimerText, STextBlock)
			//.Text(TEXT("Hello"))
		]
	];
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SShowTimer::SetShowTimer(FText TimerText)
{
	ShowTimerText->SetText(TimerText);
}
