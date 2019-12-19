// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SlateTick.h"
#include "SerialPort.h" // Э��������  SerialPort.h δ�������༭
#include "Data/EnumData.h"
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

	virtual void Init() override;

public:

	UPROPERTY(BlueprintReadOnly)
		float RollAilerons;

	UPROPERTY(BlueprintReadOnly)
		float PitchElevator;

	UPROPERTY(BlueprintReadOnly)
		float Throttle;

	UPROPERTY(BlueprintReadOnly)
		float YawRudder;

	UPROPERTY(BlueprintReadOnly)
		int Chan5;

	UPROPERTY(BlueprintReadOnly)
		float Chan6;

	UPROPERTY(BlueprintReadOnly)
		int Chan7;

	UPROPERTY(BlueprintReadOnly)
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