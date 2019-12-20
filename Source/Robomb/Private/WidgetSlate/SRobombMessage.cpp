// Fill out your copyright notice in the Description page of Project Settings.


#include "SRobombMessage.h"
#include "SlateOptMacros.h"
#include "SBorder.h"
#include "SBoxPanel.h"
#include "STextBlock.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SRobombMessage::Construct(const FArguments& InArgs)
{
	/* 显示飞机的所有信息 */
	ChildSlot
	[
		// Populate the widget
		SNew(SBorder)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			[
				SNew(SVerticalBox)
				+ SVerticalBox::Slot()
				[
					SNew(STextBlock)
					.Text(FText::FromString(TEXT("Robomb Message")))
				]
			]
			+ SHorizontalBox::Slot()
			[
				SNew(SVerticalBox)
				+ SVerticalBox::Slot()
				[
					SNew(STextBlock)
					.Text(FText::FromString(TEXT("RC Message")))
				]
			]
			+ SHorizontalBox::Slot()
			[
				SNew(SVerticalBox)
				+ SVerticalBox::Slot()
				[
					SNew(STextBlock)
					.Text(FText::FromString(TEXT("Rests Message")))
				]
			]
		]
	];
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
