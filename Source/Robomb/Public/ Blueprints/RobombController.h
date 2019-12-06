// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "RobombController.generated.h"

 // �ж����ֻ�������
enum ModeOperation
{
	NoneModeOoperation, // û�в���ģʽ
	AmericaModeOoperation, // ��������ģʽ
	JapanModeOoperation, // �ձ�����ģʽ
};

UCLASS()
class ROBOMB_API ARobombController : public APlayerController
{
	GENERATED_BODY()

public:

	ARobombController();
	~ARobombController();

public:

	// RC �ظ˵�ֵ
	UPROPERTY(BlueprintReadOnly)
		float RollAilerons;
	UPROPERTY(BlueprintReadOnly)
		float PitchElevator;
	UPROPERTY(BlueprintReadOnly)
		float Throttle;
	UPROPERTY(BlueprintReadOnly)
		float YawRudder;
	UPROPERTY(BlueprintReadOnly)
		float Chan5;
	UPROPERTY(BlueprintReadOnly)
		float Chan6;
	UPROPERTY(BlueprintReadOnly)
		float Chan7;
	UPROPERTY(BlueprintReadOnly)
		float Chan8;

	// ����ģʽ
	ModeOperation ModeOpera;

private:

	void Init();

	void UpdataRCData();

};
