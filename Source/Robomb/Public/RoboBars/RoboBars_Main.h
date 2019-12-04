// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
// #include "mavlink/mavlink_types.h"
#include "RoboBars_Main.generated.h"

UCLASS()
class ROBOMB_API ARoboBars_Main : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ARoboBars_Main();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:

	bool AmericaMode, JapanMode;

private:

	// mavlink_message_t Message;

public:

	void RC_GetData();


};
