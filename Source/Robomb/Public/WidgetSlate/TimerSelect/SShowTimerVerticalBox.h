// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class ROBOMB_API SShowTimerVerticalBox : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SShowTimerVerticalBox)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

private:

	TSharedPtr<class SVerticalBox> ShowTimerVertical;
	TSharedPtr<class SShowTimer> ShowTiemr;

private:

	void SpawnShowTimer();

private:

	virtual FReply OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;

	virtual FReply OnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;

};
