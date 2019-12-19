// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SlateTick.h"
#include "SerialPort.h" // 协议编译出错  SerialPort.h 未解决错误编辑
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

	// 是否成功连接
	int CheckCompID;

	// 线程
	class SlateTick * RcData;    // New 线程

	FRunnableThread *Thread1;   // 执行线程

	// 一个 FSerialPort 类
	FSerialPort Serial;

	// 协议
	mavlink_message_t Message;


public:

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

	void GetRcData();

private:

	// 运行 JAVA 开发的环境
	void OPEN_COM();

	// 线程在这里运行 GetRcData
	void TestThread();

	// 不太清楚这是什么
	bool Open(int Port, int BaudRate);

	// 该事件没有地方使用
	void ShutDown();

	// 在 ShutDown 里使用
	void Close();

	// GetRcData 里使用
	bool ReadMessage(mavlink_message_t &InMessage);

	// GetRcData 里使用
	int Write(mavlink_message_t &InMessage);
};