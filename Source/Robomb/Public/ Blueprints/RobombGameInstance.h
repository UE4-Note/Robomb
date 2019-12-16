// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
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

private:

	// 协议
	mavlink_message_t Message;

	ASerialPort SerialPort;

	FRunnableThread *Threadl;

private:

	// RC 控制方式
	ModeOperation ModeOpera;

public:

	virtual void Init() override;

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

public:

	// 调用此方法测试多线程
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