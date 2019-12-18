// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SerialPort.h" // 协议编译出错  SerialPort.h 未解决错误编辑
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
	// 调用此方法测试多线程
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
	//新起线程
	class SlateTick * RcData;    //执行线程new
	FRunnableThread *Thread1;   //执行线程1

	mavlink_message_t message;
	bool flag;
	Serial_Port serial;
	UFUNCTION(BlueprintCallable)
		bool open(int port, int baudRate);
	bool read_message(mavlink_message_t &inmessage);
	int write(mavlink_message_t &inmessage);
	UFUNCTION(BlueprintCallable)
		void close();

	//获得机器码
	UFUNCTION(BlueprintCallable, Category = "getHardwareID")
		FString getHardwareID();
	UFUNCTION(BlueprintCallable, Category = "getHardwareID")
		FString getMACID();
	UFUNCTION(BlueprintCallable, Category = "getHardwareID")
		FString GetSystemId();
	//电脑信息
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

	// 协议
	mavlink_message_t Message;

	ASerialPort SerialPort;

	FRunnableThread *Threadl;

private:

	// RC 控制方式
	ModeOperation ModeOpera;

	// != 4 没有连接设备
	int32 CheckCompid;

public:

	URobombGameInstance();

	~URobombGameInstance();

	virtual void Init() override;

public:

	mavlink_message_t GetMessage() { return Message; };

public:

	// 获取 RC 遥感数据
	UFUNCTION(BlueprintCallable)
		void SetModeOperation(ModeOperation InModeOpera) { ModeOpera = InModeOpera; };

	UFUNCTION(BlueprintCallable)
		ModeOperation GetModeOperation() { return ModeOpera; };

	//获得机器码
	UFUNCTION(BlueprintCallable, Category = "GetHardwareID")
		FString GetMachineId();

	UFUNCTION(BlueprintCallable, Category = "GetHardwareID")
		FString GetMacAddressString();

	UFUNCTION(BlueprintCallable, Category = "GetHardwareID")
		FString GetOperatingSystemId();

	//电脑信息
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

	// 调用此方法测试多线程
	void TestThread();

	bool Open(int Port, int BaudRate);

	// ShutDown 里调用
	void Close();

	// 没有任何地方调用
	void ShutDown();

	void bConnectingDevice();

	bool ReadMessage(mavlink_message_t &InMessage);

	void InitData();
*/
	
};