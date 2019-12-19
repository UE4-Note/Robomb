// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class ROBOMB_API SShowTimer : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SShowTimer)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

private:

	TSharedPtr<class STextBlock> ShowTimerText;

public:

	void SetShowTimer(FText TimerText);

};
