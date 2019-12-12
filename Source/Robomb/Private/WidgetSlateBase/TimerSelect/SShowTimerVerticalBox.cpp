// Fill out your copyright notice in the Description page of Project Settings.


#include "SShowTimerVerticalBox.h"
#include "SlateOptMacros.h"
#include "SBoxPanel.h"
#include "WidgetSlateBase/TimerSelect/SShowTimer.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SShowTimerVerticalBox::Construct(const FArguments& InArgs)
{
	ChildSlot
	[
		// Populate the widget
		// ѭ�������������������������ʾ���ݣ���ʾʱ��ģ���
		// ����»��������ƶ������ɣ�һ��λ�ú�ɾ��������ʾʵ��ģ���
		SAssignNew(ShowTimerVertical, SVerticalBox)
	];
}

void SShowTimerVerticalBox::SpawnShowTimer()
{
	for (int32 i = 0; i < 3; i++)
	{
		ShowTimerVertical->AddSlot()
			[
				SNew(SShowTimer)
			];
	}
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION

FReply SShowTimerVerticalBox::OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	return FReply::Handled();
}

FReply SShowTimerVerticalBox::OnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	return FReply::Handled();
}
