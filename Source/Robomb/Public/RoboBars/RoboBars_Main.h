// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "RoboBars_Main.generated.h"

UENUM()
// 判断美手还是日手
enum ModeOperation
{
	NoneModeOoperation, // 没有操作模式
	AmericaModeOoperation, // 美国操作模式
	JapanModeOoperation, // 日本操作模式
};

UCLASS()
class ROBOMB_API ARoboBars_Main : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ARoboBars_Main();
	~ARoboBars_Main();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

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
public:

	void GetRCData();

private:

	void Init();

	void UpdataRCData();
};
