// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SerialPort.h" // 协议编译出错  SerialPort.h 未解决错误编辑
#include "GameFramework/Pawn.h"
#include "mavlink/mavlink_helpers.h"
#include "RoboBars_Main.generated.h"

class ASerialPort;

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

	// 协议
	mavlink_message_t Message;

	ASerialPort SerialPort;

	FRunnableThread *Thread1;

private:

	int CheckCompId;
	// RC 控杆的值
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
	float GetChan5() { return Chan5; };
	UFUNCTION(BlueprintCallable)
	float GetChan6() { return Chan6; };
	UFUNCTION(BlueprintCallable)
	float GetChan7() { return Chan7; };
	UFUNCTION(BlueprintCallable)
	float GetChan8() { return Chan8; };

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

	void Init();

	void GetRCData();

	bool ReadMessage(mavlink_message_t &InMessage);

	int Write(mavlink_message_t &InMessage);

};