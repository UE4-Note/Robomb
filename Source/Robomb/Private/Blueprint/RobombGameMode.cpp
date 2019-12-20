// Fill out your copyright notice in the Description page of Project Settings.


#include "RobombGameMode.h"
#include "RobombHUD.h"
#include "RobombController.h"
#include "RobombGameState.h"

ARobombGameMode::ARobombGameMode()
{
	PlayerControllerClass = ARobombController::StaticClass();
	PlayerStateClass = ARobombGameState::StaticClass();
	HUDClass = ARobombHUD::StaticClass();
}