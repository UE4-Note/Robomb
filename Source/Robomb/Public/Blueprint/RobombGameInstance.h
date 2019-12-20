// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SerialPort.h" // 协议编译出错  SerialPort.h 未解决错误编辑
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

private:

	URobombGameInstance();

	~URobombGameInstance();

	virtual void Init() override;

public:

	// 单例 GameInstance
	static const URobombGameInstance* Get() { return RobombGameInstance; };

private:

	static URobombGameInstance* RobombGameInstance;

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

	// CompID
	int CheckCompID;

	// 线程 // New 线程
	class SlateTick * RcData;   

	// 执行线程
	FRunnableThread *Thread1;   

	// 一个 FSerialPort 类
	FSerialPort Serial;

	// 协议
	mavlink_message_t Message;

public:
	// UFUNCTION(BlueprintCallable, Category = "GetRcData")
	void GetRcData();

	// UFUNCTION(BlueprintCallable)
	float GetRollAilerons() { return RollAilerons; };

	// UFUNCTION(BlueprintCallable)
	float GetPitchElevator() { return PitchElevator; };

	// UFUNCTION(BlueprintCallable)
	float GetThrottle() { return Throttle; };

	// UFUNCTION(BlueprintCallable)
	float GetYawRudder() { return YawRudder; };

	// UFUNCTION(BlueprintCallable)
	int GetChan5() { return Chan5; };

	// UFUNCTION(BlueprintCallable)
	float GetChan6() { return Chan6; };

	// UFUNCTION(BlueprintCallable)
	int GetChan7() { return Chan7; };

	// UFUNCTION(BlueprintCallable)
	float GetChan8() { return Chan8; };

public:

	void GameQuit();

public:

	// 获得机器码
	// UFUNCTION(BlueprintCallable, Category = "GetHardwareID")
	FString GetMachineId();

	// UFUNCTION(BlueprintCallable, Category = "GetHardwareID")
	FString GetMacAddressString();

	// UFUNCTION(BlueprintCallable, Category = "GetHardwareID")
	FString GetOperatingSystemId();

	// 电脑信息
	// UFUNCTION(BlueprintCallable, Category = "GetComputerConfig")
	FString GetOSVersion();

	// UFUNCTION(BlueprintCallable, Category = "GetComputerConfig")
	FString GetCPUBrand();

	// UFUNCTION(BlueprintCallable, Category = "GetComputerConfig")
	FString GetPrimaryGPUBrand();

	// UFUNCTION(BlueprintCallable, Category = "GetComputerConfig")
	void GetOSVersions(FString &OSLabel, FString &OSVersion);

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

private:

	// 设备是否连接
	void Equipment();

};