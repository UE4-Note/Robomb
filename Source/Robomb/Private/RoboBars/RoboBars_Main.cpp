// Fill out your copyright notice in the Description page of Project Settings.


#include "RoboBars_Main.h"


// Sets default values
ARoboBars_Main::ARoboBars_Main()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

ARoboBars_Main::~ARoboBars_Main()
{

}

// Called when the game starts or when spawned
void ARoboBars_Main::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARoboBars_Main::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ARoboBars_Main::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


void ARoboBars_Main::Init()
{
	// Init
	RollAilerons = PitchElevator = Throttle = YawRudder = Chan5 = Chan6 = Chan7 = Chan8 = 0;

	// 操作模式默认是美国手
	ModeOpera = ModeOperation::AmericaModeOoperation;
}

void ARoboBars_Main::UpdataRCData()
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
		//一般固定翼副翼接1通道，升降舵接2通道，油门3通道，方向舵4通道，起落架5通道，襟翼6通道。
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

