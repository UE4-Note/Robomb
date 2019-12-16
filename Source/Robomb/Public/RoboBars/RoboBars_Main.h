// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SerialPort.h" // Э��������  SerialPort.h δ�������༭
#include "GameFramework/Pawn.h"
#include "mavlink/mavlink_helpers.h"
#include "RoboBars_Main.generated.h"

class ASerialPort;

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

private:

	// ����ģʽ
	ModeOperation ModeOpera;

	// RC �ظ˵�ֵ
	// UPROPERTY(BlueprintReadOnly)
	float RollAilerons;
	// UPROPERTY(BlueprintReadOnly)
	float PitchElevator;
	// UPROPERTY(BlueprintReadOnly)
	float Throttle;
	// UPROPERTY(BlueprintReadOnly)
	float YawRudder;
	// UPROPERTY(BlueprintReadOnly)
	float Chan5;
	// UPROPERTY(BlueprintReadOnly)
	float Chan6;
	// UPROPERTY(BlueprintReadOnly)
	float Chan7;
	// UPROPERTY(BlueprintReadOnly)
	float Chan8;

private:

	// Э��
	mavlink_message_t Message;

	mavlink_rc_channels_t rc;

	ASerialPort SerialPort;

	FRunnableThread *Thread1;

public:

	// ��ȡ RC ң������
	UFUNCTION(BlueprintCallable)
	void SetModeOperation() {};
	UFUNCTION(BlueprintCallable)
	float GetRollAilerons() { return RollAilerons; };
	UFUNCTION(BlueprintCallable)
	float GetPitchElevator() { return PitchElevator; };
	UFUNCTION(BlueprintCallable)
	float GetThrottle() { return Throttle; };
	UFUNCTION(BlueprintCallable)
	float GetYawRudder() { return YawRudder; };
	UFUNCTION(BlueprintCallable)
	float GetChan5() { return Chan5; };
	UFUNCTION(BlueprintCallable)
	float GetChan6() { return Chan6; };
	UFUNCTION(BlueprintCallable)
	float GetChan7() { return Chan7; };
	UFUNCTION(BlueprintCallable)
	float GetChan8() { return Chan8; };

public:

	UFUNCTION(BlueprintCallable)
	void OPEN_COM();
	// ���ô˷������Զ��߳�
	UFUNCTION(BlueprintCallable)
	void TestThread();
	UFUNCTION(BlueprintCallable)
	void ShutDown();
	UFUNCTION(BlueprintCallable)
	void Close();
	UFUNCTION(BlueprintCallable)
	bool Open(int Port, int BaudRate);



private:

	void Init();

	void GetRCData();

	bool ReadMessage(mavlink_message_t &Message);

	int Write(mavlink_message_t &Message);

};