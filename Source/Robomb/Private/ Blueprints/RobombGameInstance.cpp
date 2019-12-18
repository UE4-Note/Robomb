// Fill out your copyright notice in the Description page of Project Settings.


#include "RobombGameInstance.h"
#include "RunnableThread.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Windows.h"
#include "Engine/Engine.h"
#include "RunnableThread.h"
#include "IPTypes.h"
#include "IPHlpApi.h"
#include "SlateTick.h"

URobombGameInstance::URobombGameInstance()
	: RcData(nullptr)
	, Thread1(nullptr)

{
}


void URobombGameInstance::OPEN_COM()
{
	// 	WinExec("D:\\project\\test\\mavlink.bat", SW_HIDE);
	system("D:\\project\\test\\mavlink.bat");
	// 	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Green, TEXT(" ok"));
}
void URobombGameInstance::TestThread()
{
	if (FPlatformProcess::SupportsMultithreading())
	{
		RcData = new SlateTick(this);
		Thread1 = FRunnableThread::Create(RcData, TEXT("线程自定义"));
		/*open(3,9600);*/

	}
}

void URobombGameInstance::getrcdata()
{
	read_message(message);

	if (message.msgid == MAVLINK_MSG_ID_HEARTBEAT) {
		mavlink_message_t msg;
		mavlink_msg_request_data_stream_pack(message.sysid, message.compid, &msg, message.sysid, message.compid, MAV_DATA_STREAM_ALL, /*MAV_DATA_STREAM_RC_CHANNELS*/2, 10);
		write(msg);
		return;
	}


	else if (message.msgid == MAVLINK_MSG_ID_RC_CHANNELS)
	{
		mavlink_rc_channels_t rc;
		mavlink_msg_rc_channels_decode(&message, &rc);

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
		//默认是常规手   //美国手的控
		if (select_HandModel)
		{
			IsModel1 = false;
			IsModel2 = true;
		}
		else
		{
			IsModel1 = true;
			IsModel2 = false;
		}
		//模式里面 Model1是日本手  Model2是美国手
		//本次Model1是常规   model2是当前控的反向手
		if (IsModel1)
		{
			RollAilerons = rc.chan1_raw;
			PitchElevator = rc.chan2_raw;
			Throttle = rc.chan3_raw;
			YawRudder = rc.chan4_raw;
			chan5 = rc.chan5_raw;
			chan6 = rc.chan6_raw;
			chan7 = rc.chan7_raw;
			chan8 = rc.chan8_raw;
			//一般固定翼副翼接1通道，升降舵接2通道，油门3通道，方向舵4通道，起落架5通道，襟翼6通道。
		}
		else if (IsModel2)
		{
			RollAilerons = rc.chan1_raw;
			Throttle = (rc.chan2_raw * -1) + 2998;
			PitchElevator = (rc.chan3_raw * -1) + 2998;
			YawRudder = rc.chan4_raw;
			chan5 = rc.chan5_raw;
			chan6 = rc.chan6_raw;
			chan7 = rc.chan7_raw;
			chan8 = rc.chan8_raw;
		}

	}
	checkCompid = message.compid;
}


void URobombGameInstance::Shutdown()
{
	close();
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



bool URobombGameInstance::open(int port, int baudRate) {

	if (!serial.Open(port, baudRate))
		return false;
	else {
		return true;
	}
}

bool URobombGameInstance::read_message(mavlink_message_t &inmessage) {
	uint8_t          cp;
	mavlink_status_t status;
	uint8_t          msgReceived = false;

	int nBytesRead = serial.ReadData(&cp, sizeof(&cp));
	if (nBytesRead > 0) {
		msgReceived = mavlink_parse_char(MAVLINK_COMM_0, cp, &inmessage, &status);
	}
	return msgReceived;
}
int URobombGameInstance::write(mavlink_message_t &inmessage) {
	char buf[300];//256
	//将消息转换为缓冲区
	unsigned len = mavlink_msg_to_send_buffer((uint8_t*)buf, &inmessage);

	return serial.SendData(buf, len);
}

void URobombGameInstance::close() {
	serial.Close();
}

FString URobombGameInstance::getHardwareID()
{
	return FPlatformMisc::GetMachineId().ToString();
}

FString URobombGameInstance::getMACID()
{
	return FPlatformMisc::GetMacAddressString();
}

FString URobombGameInstance::GetSystemId()
{
	return FPlatformMisc::GetOperatingSystemId();
}
//////电脑信息
FString URobombGameInstance::getosversion()
{
	return FPlatformMisc::GetOSVersion();
}

FString URobombGameInstance::getCPUB()
{
	return FPlatformMisc::GetCPUBrand();
}


FString URobombGameInstance::getGPUB()
{
	return FPlatformMisc::GetPrimaryGPUBrand();
}

void URobombGameInstance::getOSV(FString & OSLabel, FString & OSVersion)
{
	FPlatformMisc::GetOSVersions(OSLabel, OSVersion);
}













/*
URobombGameInstance::URobombGameInstance()
	// :RcData(nullptr),Threadl(nullptr)

{

}

URobombGameInstance::~URobombGameInstance()
{

}

void URobombGameInstance::Init()
{
	OPEN_COM();
	TestThread();
	Open(3, 115200);
	InitData();
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

// 电脑信息
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

void URobombGameInstance::GetOSVersions(FString &OSLabel, FString &OSVersion)
{
	FPlatformMisc::GetOSVersions(OSLabel, OSVersion);
}

void URobombGameInstance::OPEN_COM()
{
	// 调用 Java 开发的运行环境
	system("D:\\project\\test\\mavlink.bat");
}

void URobombGameInstance::TestThread()
{
	if (FPlatformProcess::SupportsMultithreading())
	{
		// RcData = new FSaleTicket(this);
		// Thread1 = FRunnableThread::Create(RcData, TEXT("线程自定义"));
	}
}

bool URobombGameInstance::Open(int Port, int BaudRate)
{
	if (!SerialPort.Open(Port, BaudRate))
	{
		return false;
	}
	else
	{
		return true;
	}
}

void URobombGameInstance::Close()
{
	SerialPort.Close();
}

void URobombGameInstance::ShutDown()
{
	Close();
	// 	if (RcData)
	// 	{
	// 		RcData->Stop();
	// 	}
	// 
	if (Threadl)
	{
		Threadl->Suspend(true);
		Threadl->Kill(false);
		delete Threadl;
		Threadl = nullptr;
	}
}

void URobombGameInstance::bConnectingDevice()
{
	ReadMessage(Message);
	CheckCompid = Message.compid;
	if (CheckCompid != 4)
	{
		UE_LOG(LogTemp, Log, TEXT("没有连接设备"));
	}
}

bool URobombGameInstance::ReadMessage(mavlink_message_t &InMessage)
{
	uint8_t cp;
	uint8_t MsgReceived = false;
	mavlink_status_t Status;

	int BytesRead = SerialPort.ReadData(&cp, sizeof(&cp));
	if (BytesRead > 0) {
		MsgReceived = mavlink_parse_char(MAVLINK_COMM_0, cp, &InMessage, &Status);
	}
	return MsgReceived;
}

void URobombGameInstance::InitData()
{
	ModeOpera = ModeOperation::AmericaModeOoperation;
}
*/