// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class ROBOMB_API SRobombMessage : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SRobombMessage)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

private:
	
	TSharedPtr<class SVerticalBox> RobombMessage;
		
	TSharedPtr<class SVerticalBox> RCMessage;

	TSharedPtr<class SVerticalBox> RestsMessage;

};
