// Fill out your copyright notice in the Description page of Project Settings.

#include "RoboBars_Main.h"
#include "RunnableThread.h"
#include "Engine/Engine.h"
#include "Paths.h"


// Sets default values
ARoboBars_Main::ARoboBars_Main()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// OPEN_COM();
}

ARoboBars_Main::~ARoboBars_Main()
{

}

// Called when the game starts or when spawned
void ARoboBars_Main::BeginPlay()
{
	Super::BeginPlay();

	Init();

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


void ARoboBars_Main::OPEN_COM()
{
	FString Paths = FPlatformProcess::BaseDir();
	UE_LOG(LogTemp, Log, TEXT(""));
	system("D:\\project\\test\\mavlink.bat");
}

void ARoboBars_Main::TestThread()
{
	if (FPlatformProcess::SupportsMultithreading())
	{
		// RcData = new FSaleTicket(this);
		// Thread1 = FRunnableThread::Create(RcData, TEXT("�߳��Զ���"));
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

	// ����ģʽĬ����������
	ModeOpera = ModeOperation::AmericaModeOoperation;
}

void ARoboBars_Main::GetRCData()
{
	switch (ModeOpera)
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
		//һ��̶������1ͨ�����������2ͨ��������3ͨ���������4ͨ���������5ͨ��������6ͨ����
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

bool ARoboBars_Main::ReadMessage(mavlink_message_t &Message)
{
	uint8_t Cp;
	uint8_t MsgReceived = false;
	mavlink_status_t Status;

	int BytesRead = SerialPort.ReadData(&Cp, sizeof(&Cp));
	if (BytesRead > 0) {
		MsgReceived = mavlink_parse_char(MAVLINK_COMM_0, Cp, &Message, &Status);
	}
	return MsgReceived;
}

int ARoboBars_Main::Write(mavlink_message_t &Message)
{
	char Buf[300];//256
	//����Ϣת��Ϊ������
	unsigned Len = mavlink_msg_to_send_buffer((uint8_t*)Buf, &Message);

	return SerialPort.SendData(Buf, Len);
}
