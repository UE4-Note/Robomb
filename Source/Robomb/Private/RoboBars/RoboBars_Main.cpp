// Fill out your copyright notice in the Description page of Project Settings.


#include "RoboBars_Main.h"


// Sets default values
ARoboBars_Main::ARoboBars_Main()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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

void ARoboBars_Main::RC_GetData()
{
	/*	
	if (Message.msgid == MAVLINK_MSG_ID_HEARTBEAT)
	{
		mavlink_message_t Msg;
		mavlink_msg_request_data_stream_pack(Message.sysid, Message.compid, &Msg, Message.sysid, Message.compid, MAV_DATA_STREAM_ALL, 2, 10);
		return;
	}
	*/
}

