// Fill out your copyright notice in the Description page of Project Settings.

#include "RoboBars_Main.h"
#include "RunnableThread.h"
#include "Engine/Engine.h"
#include "Paths.h"
#include "Data/EnumData.h"


// Sets default values
ARoboBars_Main::ARoboBars_Main()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// OPEN_COM();
	Open(3, 115200);
}

ARoboBars_Main::~ARoboBars_Main()
{

}

// Called when the game starts or when spawned
void ARoboBars_Main::BeginPlay()
{
	Super::BeginPlay();

	Init();

	Open(3, 115200);
}

// Called every frame
void ARoboBars_Main::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	GetRCData();

}

// Called to bind functionality to input
void ARoboBars_Main::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ARoboBars_Main::TestThread()
{
	if (FPlatformProcess::SupportsMultithreading())
	{
		// RcData = new FSaleTicket(this);
		// Thread1 = FRunnableThread::Create(RcData, TEXT("线程自定义"));
	}
}

void ARoboBars_Main::ShutDown()
{
	Close();
// 	if (RcData)
// 	{
// 		RcData->Stop();
// 	}
// 
	if (Thread1)
	{
		Thread1->Suspend(true);
		Thread1->Kill(false);
		delete Thread1;
		Thread1 = nullptr;
	}
}

void ARoboBars_Main::Close()
{
	SerialPort.Close();
}

bool ARoboBars_Main::Open(int Port, int BaudRate)
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

void ARoboBars_Main::Init()
{
	// Init
	Chan5 = 0;
	Chan6 = 0;
	Chan7 = 0;
	Chan8 = 0;
	Throttle = 0;
	YawRudder = 0;
	RollAilerons = 0;
	PitchElevator = 0;
}

void ARoboBars_Main::GetRCData()
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
			UE_LOG(LogTemp, Log, TEXT("Error : Mode Ooperation Error !"));
			break;
		}
	}
	else
	{
		// check(false);
	}
	CheckCompId = Message.compid;
}

bool ARoboBars_Main::ReadMessage(mavlink_message_t &InMessage)
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

int ARoboBars_Main::Write(mavlink_message_t &InMessage)
{
	char Buf[300];//256
	//将消息转换为缓冲区
	unsigned Len = mavlink_msg_to_send_buffer((uint8_t*)Buf, &InMessage);

	return SerialPort.SendData(Buf, Len);
}
