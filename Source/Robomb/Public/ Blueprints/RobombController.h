// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "RobombController.generated.h"

 // 判断美手还是日手
enum ModeOperation
{
	NoneModeOoperation, // 没有操作模式
	AmericaModeOoperation, // 美国操作模式
	JapanModeOoperation, // 日本操作模式
};

UCLASS()
class ROBOMB_API ARobombController : public APlayerController
{
	GENERATED_BODY()

public:

	ARobombController();
	~ARobombController();

public:

	// RC 控杆的值
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

	// 操作模式
	ModeOperation ModeOpera;

private:

	void Init();

	void UpdataRCData();

};
