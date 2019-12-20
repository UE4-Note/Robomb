// Fill out your copyright notice in the Description page of Project Settings.


#include "RobombGameInstance.h"
#include "Engine/World.h"
#include "Engine/Engine.h"
#include "RunnableThread.h"
#include "Engine/GameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "GameFramework/PlayerController.h"

URobombGameInstance* URobombGameInstance::RobombGameInstance = nullptr;

URobombGameInstance::URobombGameInstance()
	: RcData(nullptr)
	, Thread1(nullptr)
{
	RobombGameInstance = this;
}

URobombGameInstance::~URobombGameInstance()
{
	ShutDown();
}

void URobombGameInstance::Init()
{
	OPEN_COM();
 	TestThread();
// 	Open(0, 115200);
// 	Open(1, 115200);
// 	Open(2, 115200);
	Open(3, 115200);
// 	Open(4, 115200);
// 	Open(5, 115200);
// 	Open(6, 115200);
// 	Open(7, 115200);
// 	Open(8, 115200);
// 	Open(9, 115200);
	Equipment();
}

void URobombGameInstance::OPEN_COM()
{
	system("D:\\project\\test\\mavlink.bat");
}

void URobombGameInstance::TestThread()
{
	if (FPlatformProcess::SupportsMultithreading())
	{
		RcData = new SlateTick(this);
		Thread1 = FRunnableThread::Create(RcData, TEXT("线程自定义"));
	}
}

bool URobombGameInstance::Open(int Port, int BaudRate) {

	if (!Serial.Open(Port, BaudRate))
		return false;
	else {
		return true;
	}
}

void URobombGameInstance::ShutDown()
{
	Close();
	if (RcData)
	{
		RcData->Stop();
	}

	if (Thread1)
	{
		Thread1->Suspend(true);
		Thread1->Kill(false);
		delete Thread1;
		Thread1 = nullptr;
	}
}

void URobombGameInstance::Close()
{
	Serial.Close();
}

void URobombGameInstance::GetRcData()
{
	ReadMessage(Message);

	if (Message.msgid == MAVLINK_MSG_ID_HEARTBEAT) {
		mavlink_message_t Msg;
		mavlink_msg_request_data_stream_pack(Message.sysid, Message.compid, &Msg, Message.sysid, Message.compid, MAV_DATA_STREAM_ALL, /*MAV_DATA_STREAM_RC_CHANNELS*/2, 10);
		Write(Msg);
		return;
	}
	else if (Message.msgid == MAVLINK_MSG_ID_RC_CHANNELS)
	{
		mavlink_rc_channels_t rc;
		mavlink_msg_rc_channels_decode(&Message, &rc);
		/*========== 不能删不能删 =============*/
		if (rc.chan1_raw == 0)
		{
			return;
		}
		if (rc.chan7_raw == 0)
		{
			return;
		}
		if (rc.chan5_raw == 0)
		{
			return;
		}
		/*========== 不能删不能删 =============*/
		ModeOperation Operation = ModeOperation::NoneModeOoperation;
		switch (Operation)
		{
		case NoneModeOoperation:
		case AmericaModeOoperation:
			RollAilerons = rc.chan1_raw;
			Throttle = (rc.chan2_raw * -1) + 2998;
			PitchElevator = (rc.chan3_raw * -1) + 2998;
			YawRudder = rc.chan4_raw;
			Chan5 = rc.chan5_raw;
			Chan6 = rc.chan6_raw;
			Chan7 = rc.chan7_raw;
			Chan8 = rc.chan8_raw;
			//一般固定翼副翼接1通道，升降舵接2通道，油门3通道，方向舵4通道，起落架5通道，襟翼6通道。
			break;
		case JapanModeOoperation:
			RollAilerons = rc.chan1_raw;
			PitchElevator = rc.chan2_raw;
			Throttle = rc.chan3_raw;
			YawRudder = rc.chan4_raw;
			Chan5 = rc.chan5_raw;
			Chan6 = rc.chan6_raw;
			Chan7 = rc.chan7_raw;
			Chan8 = rc.chan8_raw;
			break;
		default:
			check(0);
			break;
		}
	}

	CheckCompID = Message.compid;
}

bool URobombGameInstance::ReadMessage(mavlink_message_t &InMessage) 
{
	uint8_t          cp;
	mavlink_status_t Status;
	uint8_t          MsgReceived = false;

	int BytesRead = Serial.ReadData(&cp, sizeof(&cp));
	if (BytesRead > 0) {
		MsgReceived = mavlink_parse_char(MAVLINK_COMM_0, cp, &InMessage, &Status);
	}
	return MsgReceived;
}

int URobombGameInstance::Write(mavlink_message_t &InMessage) 
{
	char buf[300];//256

	//将消息转换为缓冲区
	unsigned len = mavlink_msg_to_send_buffer((uint8_t*)buf, &InMessage);

	return Serial.SendData(buf, len);
}

void URobombGameInstance::Equipment()
{
	// 延迟 2m 退出
	FPlatformProcess::Sleep(2.0);

	// 判断是否连接到设备没有退出
	if (CheckCompID == 4)
	{
		GEngine->AddOnScreenDebugMessage(1, 1000.0, FColor::Red, TEXT("Get Equipment"));
		return;
	}

	FPlatformProcess::Sleep(2.0);
	GEngine->AddOnScreenDebugMessage(1, 1000.0, FColor::Red, TEXT("GameQuit"));
	GameQuit();
}

void URobombGameInstance::GameQuit()
{
// 	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);
// 	UKismetSystemLibrary::QuitGame(this, PlayerController, EQuitPreference::Quit, true);
}

FString URobombGameInstance::GetMachineId()
{
	return FPlatformMisc::GetMachineId().ToString();
}

FString URobombGameInstance::GetMacAddressString()
{
	return FPlatformMisc::GetMacAddressString();
}

FString URobombGameInstance::GetOperatingSystemId()
{
	return FPlatformMisc::GetOperatingSystemId();
}

//////电脑信息
FString URobombGameInstance::GetOSVersion()
{
	return FPlatformMisc::GetOSVersion();
}

FString URobombGameInstance::GetCPUBrand()
{
	return FPlatformMisc::GetCPUBrand();
}

FString URobombGameInstance::GetPrimaryGPUBrand()
{
	return FPlatformMisc::GetPrimaryGPUBrand();
}

void URobombGameInstance::GetOSVersions(FString & OSLabel, FString & OSVersion)
{
	FPlatformMisc::GetOSVersions(OSLabel, OSVersion);
}