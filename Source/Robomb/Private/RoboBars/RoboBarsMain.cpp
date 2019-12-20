// Fill out your copyright notice in the Description page of Project Settings.

#include "RoboBarsMain.h"
#include "RobombGameInstance.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/PostProcessComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "WidgetComponent.h"
#include "Kismet/KismetMathLibrary.h"


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
	MyDeltaTime = DeltaTime;
}

void ARoboBarsMain::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ARoboBarsMain::GoUpAndDown(float InThrottle, float InSensitivity /*= 1*/)
{
	if (SKeletalMeshComp)
	{
		float A = (InThrottle - RcMessage) * InSensitivity;
		FVector B = SKeletalMeshComp->GetPhysicsLinearVelocity(NAME_None);
		FVector C = SKeletalMeshComp->GetUpVector();
		B.X = 0.0;
		B.Y = 0.0;
		B.Z = B.Z * A;
		SKeletalMeshComp->SetPhysicsLinearVelocity(B, false, NAME_None);
	}
}

void ARoboBarsMain::Rudder(float InYaw, float InSensitivity /*= 1*/)
{
	if (SKeletalMeshComp)
	{
		FVector A;
		A.X = 0;
		A.Y = 0;
		FVector B = SKeletalMeshComp->GetUpVector();
		A.Z = InYaw * B.Z;
		SKeletalMeshComp->AddTorqueInDegrees(A, NAME_None, true);
	}
}

void ARoboBarsMain::Aileron(float InRoll, float InSensitivity /*= 1*/)
{
	if (SKeletalMeshComp)
	{
		FRotator A = SKeletalMeshComp->GetComponentRotation();
		float B = UKismetMathLibrary::NormalizeToRange(InRoll, 999.0, 1999.0);
		float C = FMath::Lerp(60.0, -60.0, B);
		float D = FMath::FInterpTo(A.Roll, C, MyDeltaTime, 2.0);
		FRotator E;
		E.Roll = D;
		E.Yaw = A.Yaw;
		E.Pitch = A.Pitch;
		this->SetActorRotation(E, ETeleportType::None);
	}
}

void ARoboBarsMain::Lifting(float InPitch, float InSensitivity /*= 1*/)
{
	if (SKeletalMeshComp)
	{
		FRotator A = SKeletalMeshComp->GetComponentRotation();
		float B = UKismetMathLibrary::NormalizeToRange(InPitch, 999.0, 1999.0);
		float C = FMath::Lerp(60.0, -60.0, B);
		float D = FMath::FInterpTo(A.Pitch, C, MyDeltaTime, 2.0);
		FRotator E;
		E.Roll = E.Roll;
		E.Yaw = A.Yaw;
		E.Pitch = D;
		this->SetActorRotation(E, ETeleportType::None);
	}
}
