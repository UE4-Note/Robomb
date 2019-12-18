// Fill out your copyright notice in the Description page of Project Settings.


#include "SlateTick.h"

SlateTick::SlateTick() : GameInstance(nullptr)
{
}

SlateTick::SlateTick(class URobombGameInstance* InGameInstance) : GameInstance(InGameInstance)
{

}

uint32 SlateTick::Run()
{
	if (GameInstance == nullptr)
	{
		return 0;
	}
	while (true)
	{
		if (GameInstance)
		{
			GameInstance->getrcdata();
		}
	}
}
