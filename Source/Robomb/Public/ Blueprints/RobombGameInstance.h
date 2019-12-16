// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
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

private:

	// Э��
	mavlink_message_t Message;

	ASerialPort SerialPort;

	FRunnableThread *Threadl;

private:

	// RC ���Ʒ�ʽ
	ModeOperation ModeOpera;

public:

	virtual void Init() override;

public:

	// ��ȡ RC ң������
	UFUNCTION(BlueprintCallable)
		void SetModeOperation(ModeOperation InModeOpera) { ModeOpera = InModeOpera; };

	UFUNCTION(BlueprintCallable)
		ModeOperation GetModeOperation() { return ModeOpera; };

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

public:

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

	void OPEN_COM();

	void InitData();

};