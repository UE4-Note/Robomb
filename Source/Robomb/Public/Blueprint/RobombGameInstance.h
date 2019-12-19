// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SerialPort.h" // Э��������  SerialPort.h δ�������༭
#include "Data/EnumData.h"
#include "Thread/SlateTick.h"
#include "Engine/GameInstance.h"
#include "mavlink/mavlink_helpers.h"
#include "RobombGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class ROBOMB_API URobombGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:

	URobombGameInstance();
	~URobombGameInstance();

	virtual void Init() override;

private:

	float RollAilerons;

	float PitchElevator;

	float Throttle;

	float YawRudder;

	int Chan5;

	float Chan6;

	int Chan7;

	float Chan8;

private:

	// �Ƿ�ɹ�����
	int CheckCompID;

	// �߳�
	class SlateTick * RcData;    // New �߳�

	FRunnableThread *Thread1;   // ִ���߳�

	// һ�� FSerialPort ��
	FSerialPort Serial;

	// Э��
	mavlink_message_t Message;

public:

	UFUNCTION(BlueprintCallable)
	float GetRollAilerons() { return RollAilerons; };

	UFUNCTION(BlueprintCallable)
	float GetPitchElevator() { return PitchElevator; };

	UFUNCTION(BlueprintCallable)
	float GetThrottle() { return Throttle; };

	UFUNCTION(BlueprintCallable)
	float GetYawRudder() { return YawRudder; };

	UFUNCTION(BlueprintCallable)
	int GetChan5() { return Chan5; };

	UFUNCTION(BlueprintCallable)
	float GetChan6() { return Chan6; };

	UFUNCTION(BlueprintCallable)
	int GetChan7() { return Chan7; };

	UFUNCTION(BlueprintCallable)
	float GetChan8() { return Chan8; };

public:

	//��û�����
	UFUNCTION(BlueprintCallable, Category = "GetHardwareID")
		FString GetMachineId();

	UFUNCTION(BlueprintCallable, Category = "GetHardwareID")
		FString GetMacAddressString();

	UFUNCTION(BlueprintCallable, Category = "GetHardwareID")
		FString GetOperatingSystemId();

	//������Ϣ
	UFUNCTION(BlueprintCallable, Category = "GetComputerConfig")
		FString GetOSVersion();

	UFUNCTION(BlueprintCallable, Category = "GetComputerConfig")
		FString GetCPUBrand();

	UFUNCTION(BlueprintCallable, Category = "GetComputerConfig")
		FString GetPrimaryGPUBrand();

	UFUNCTION(BlueprintCallable, Category = "GetComputerConfig")
		void GetOSVersions(FString &OSLabel, FString &OSVersion);

	UFUNCTION(BlueprintCallable, Category = "GetRcData")
	void GetRcData();

private:

	// ���� JAVA �����Ļ���
	void OPEN_COM();

	// �߳����������� GetRcData
	void TestThread();

	// ��̫�������ʲô
	bool Open(int Port, int BaudRate);

	// ���¼�û�еط�ʹ��
	void ShutDown();

	// �� ShutDown ��ʹ��
	void Close();

	// GetRcData ��ʹ��
	bool ReadMessage(mavlink_message_t &InMessage);

	// GetRcData ��ʹ��
	int Write(mavlink_message_t &InMessage);
};