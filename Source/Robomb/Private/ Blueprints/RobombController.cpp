// Fill out your copyright notice in the Description page of Project Settings.
// 2019-12-6 9:56 Tom

#include "RobombController.h"


ARobombController::ARobombController()
{
	Init();
}

ARobombController::~ARobombController()
{

}

void ARobombController::Init()
{
	// Init
	RollAilerons = PitchElevator = Throttle = YawRudder = Chan5 = Chan6 = Chan7 = Chan8 = 0;

	// ����ģʽĬ����������
	ModeOpera = ModeOperation::AmericaModeOoperation;
	// mavlink_rc_channels_t rc;
	// mavlink_rc_channels_t rc;
	// mavlink_msg_rc_channels_decode()
	/*
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
	*/
}

void ARobombController::UpdataRCData()
{
	switch (ModeOpera)
	{
	case NoneModeOoperation:
	case AmericaModeOoperation:
		/*
		RollAilerons = rc.chan1_raw;
		Throttle = (rc.chan2_raw * -1) + 2998;
		PitchElevator = (rc.chan3_raw * -1) + 2998;
		YawRudder = rc.chan4_raw;
		Chan5 = rc.chan5_raw;
		Chan6 = rc.chan6_raw;
		Chan7 = rc.chan7_raw;
		Chan8 = rc.chan8_raw;
		*/
		//һ��̶������1ͨ�����������2ͨ��������3ͨ���������4ͨ���������5ͨ��������6ͨ����
		break;
	case JapanModeOoperation:
		/*
		RollAilerons = rc.chan1_raw;
		PitchElevator = rc.chan2_raw;
		Throttle = rc.chan3_raw;
		YawRudder = rc.chan4_raw;
		Chan5 = rc.chan5_raw;
		Chan6 = rc.chan6_raw;
		Chan7 = rc.chan7_raw;
		Chan8 = rc.chan8_raw;
		*/
		break;
	default:
		UE_LOG(LogTemp, Log, TEXT("Error : Mode Ooperation Error !"));
		break;
	}
}
