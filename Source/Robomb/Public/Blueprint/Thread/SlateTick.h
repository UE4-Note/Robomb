// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runnable.h"
#include "RobombGameInstance.h"


/**
 * 
 */
class SlateTick : public FRunnable
{
public:

	class URobombGameInstance* GameInstance;

public:

	SlateTick();

	SlateTick(class URobombGameInstance* InGameInstance);

	virtual uint32 Run() override;

};
