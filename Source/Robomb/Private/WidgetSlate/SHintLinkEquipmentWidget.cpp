// Fill out your copyright notice in the Description page of Project Settings.


#include "SHintLinkEquipmentWidget.h"
#include "SlateOptMacros.h"
#include "SBorder.h"
#include "STextBlock.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SHintLinkEquipmentWidget::Construct(const FArguments& InArgs)
{
	ChildSlot
	[
		SNew(SBorder)
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		.ColorAndOpacity(FLinearColor(1, 1, 1, 1))
		[
			SNew(STextBlock)
			.Text(FText::FromString(TEXT("Please Link Equipment")))
		]
	];
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
