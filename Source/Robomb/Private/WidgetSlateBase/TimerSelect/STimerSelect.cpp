// Fill out your copyright notice in the Description page of Project Settings.


#include "STimerSelect.h"
#include "SlateOptMacros.h"
#include "SBox.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void STimerSelect::Construct(const FArguments& InArgs)
{
	ChildSlot
	[
		// Populate the widget
		SNew(SBox)
		// .HeightOverride(50.0)
		// .WidthOverride(170.0)

	];
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
