// Fill out your copyright notice in the Description page of Project Settings.

#include "RoboBarsMain.h"
#include "RobombGameInstance.h"


// Sets default values
ARoboBarsMain::ARoboBarsMain()
{
	PrimaryActorTick.bCanEverTick = true;
}

ARoboBarsMain::~ARoboBarsMain()
{

}

void ARoboBarsMain::BeginPlay()
{
	Super::BeginPlay();
}

void ARoboBarsMain::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ARoboBarsMain::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}
