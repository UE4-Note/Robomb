// Fill out your copyright notice in the Description page of Project Settings.


#include "SShowTimerVerticalBox.h"
#include "SlateOptMacros.h"
#include "SBoxPanel.h"
#include "SShowTimer.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SShowTimerVerticalBox::Construct(const FArguments& InArgs)
{
	ChildSlot
	[
		// Populate the widget
		// 循环生成三个或者五个，设置显示内容；显示时间模块儿
		// 点击下或上啦，移动，生成；一定位置后删除生成显示实现模块儿
		SAssignNew(ShowTimerVertical, SVerticalBox)
	];
}

void SShowTimerVerticalBox::SpawnShowTimer()
{
	for (int32 i = 0; i < 3; i++)
	{
		ShowTimerVertical->AddSlot()
			[
				SAssignNew(ShowTiemr, SShowTimer)	
			];
		ShowTiemr->SetShowTimer(FText::FromString(TEXT("")));
	}
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION

FReply SShowTimerVerticalBox::OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	// ShowTimerVertical
	return FReply::Handled();
}

FReply SShowTimerVerticalBox::OnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	return FReply::Handled();
}
