// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SerialPort.h" // Э��������  SerialPort.h δ�������༭
#include "Data/EnumData.h"
#include "Engine/GameInstance.h"
#include "mavlink/mavlink_helpers.h"
#include "SlateTick.h"
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
	// ���ô˷������Զ��߳�
	UFUNCTION(BlueprintCallable)
		void TestThread();
	UPROPERTY(BlueprintReadOnly)
		float RollAilerons;
	UPROPERTY(BlueprintReadOnly)
		float PitchElevator;
	UPROPERTY(BlueprintReadOnly)
		float Throttle;
	UPROPERTY(BlueprintReadOnly)
		float YawRudder;
	UPROPERTY(BlueprintReadOnly)
		int chan5;
	UPROPERTY(BlueprintReadOnly)
		float chan6;
	UPROPERTY(BlueprintReadOnly)
		int chan7;
	UPROPERTY(BlueprintReadOnly)
		float chan8;


	UPROPERTY(BlueprintReadOnly)
		int checkCompid;
	UPROPERTY(BlueprintReadWrite)
		bool select_HandModel = false;

	bool IsModel1;
	bool IsModel2;


	UFUNCTION(BlueprintCallable)
		void OPEN_COM();


	void getrcdata();
	UFUNCTION(BlueprintCallable)
		void Shutdown();
public:
	//�����߳�
	class SlateTick * RcData;    //ִ���߳�new
	FRunnableThread *Thread1;   //ִ���߳�1

	mavlink_message_t message;
	bool flag;
	Serial_Port serial;
	UFUNCTION(BlueprintCallable)
		bool open(int port, int baudRate);
	bool read_message(mavlink_message_t &inmessage);
	int write(mavlink_message_t &inmessage);
	UFUNCTION(BlueprintCallable)
		void close();

	//��û�����
	UFUNCTION(BlueprintCallable, Category = "getHardwareID")
		FString getHardwareID();
	UFUNCTION(BlueprintCallable, Category = "getHardwareID")
		FString getMACID();
	UFUNCTION(BlueprintCallable, Category = "getHardwareID")
		FString GetSystemId();
	//������Ϣ
	UFUNCTION(BlueprintCallable, Category = "getComputerConfig")
		FString getosversion();
	UFUNCTION(BlueprintCallable, Category = "getComputerConfig")
		FString getCPUB();
	UFUNCTION(BlueprintCallable, Category = "getComputerConfig")
		FString getGPUB();
	UFUNCTION(BlueprintCallable, Category = "getComputerConfig")
		void getOSV(FString &OSLabel, FString &OSVersion);




/*
private:

	// Э��
	mavlink_message_t Message;

	ASerialPort SerialPort;

	FRunnableThread *Threadl;

private:

	// RC ���Ʒ�ʽ
	ModeOperation ModeOpera;

	// != 4 û�������豸
	int32 CheckCompid;

public:

	URobombGameInstance();

	~URobombGameInstance();

	virtual void Init() override;

public:

	mavlink_message_t GetMessage() { return Message; };

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

private:

	void OPEN_COM();

	// ���ô˷������Զ��߳�
	void TestThread();

	bool Open(int Port, int BaudRate);

	// ShutDown �����
	void Close();

	// û���κεط�����
	void ShutDown();

	void bConnectingDevice();

	bool ReadMessage(mavlink_message_t &InMessage);

	void InitData();
*/
	
};