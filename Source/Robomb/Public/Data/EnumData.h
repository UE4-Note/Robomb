// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

UENUM()

// 判断美手还是日手
enum ModeOperation
{
	NoneModeOoperation, // 没有操作模式
	AmericaModeOoperation, // 美国操作模式
	JapanModeOoperation, // 日本操作模式
};

enum RCPosition
{
	None,
	CentrePosition,
	EndPosition,
};