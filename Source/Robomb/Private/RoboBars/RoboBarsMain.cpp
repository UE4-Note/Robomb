// Fill out your copyright notice in the Description page of Project Settings.

#include "RoboBarsMain.h"
#include "RobombGameInstance.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/PostProcessComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "WidgetComponent.h"


// Sets default values
ARoboBarsMain::ARoboBarsMain()
{
	PrimaryActorTick.bCanEverTick = true;
 	SKeletalMeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SKeletalMesh"));
	SKeletalMeshComp->RootBodyData;
	PostProcessComp = CreateDefaultSubobject<UPostProcessComponent>(TEXT("PostProcess"));
	PostProcessComp->AttachTo(SKeletalMeshComp);
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArmComp->AttachTo(SKeletalMeshComp);
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComp->AttachTo(SpringArmComp);
	// UWidgetComponent 使用需要在 .Build.cs 添加 UMG
	WidgetComp = CreateDefaultSubobject<UWidgetComponent>(TEXT("Widget"));
	WidgetComp->AttachTo(CameraComp);
}

ARoboBarsMain::~ARoboBarsMain()
{

}

void ARoboBarsMain::BeginPlay()
{
	Super::BeginPlay();
	GameInstace = URobombGameInstance::Get();
}

void ARoboBarsMain::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ARoboBarsMain::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}
