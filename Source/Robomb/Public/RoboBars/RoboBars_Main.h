// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "RoboBars_Main.generated.h"


UENUM()
// �ж����ֻ�������
enum ModeOperation
{
	NoneModeOoperation, // û�в���ģʽ
	AmericaModeOoperation, // ��������ģʽ
	JapanModeOoperation, // �ձ�����ģʽ
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
