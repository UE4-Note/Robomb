// Fill out your copyright notice in the Description page of Project Settings.


#include "RobombGameInstance.h"
#include "RunnableThread.h"

void URobombGameInstance::Init()
{
	OPEN_COM();
	Open(3, 115200);
	InitData();
}

FString URobombGameInstance::GetMachineId()
{
	return FPlatformMisc::GetMachineId().ToString();
}

FString URobombGameInstance::GetMacAddressString()
{
	return FPlatformMisc::GetMacAddressString();
}

FString URobombGameInstance::GetOperatingSystemId()
{
	return FPlatformMisc::GetOperatingSystemId();
}

// 电脑信息
FString URobombGameInstance::GetOSVersion()
{
	return FPlatformMisc::GetOSVersion();
}

FString URobombGameInstance::GetCPUBrand()
{
	return FPlatformMisc::GetCPUBrand();
}

FString URobombGameInstance::GetPrimaryGPUBrand()
{
	return FPlatformMisc::GetPrimaryGPUBrand();
}

void URobombGameInstance::GetOSVersions(FString &OSLabel, FString &OSVersion)
{
	FPlatformMisc::GetOSVersions(OSLabel, OSVersion);
}

void URobombGameInstance::TestThread()
{
	if (FPlatformProcess::SupportsMultithreading())
	{
		// RcData = new FSaleTicket(this);
		// Thread1 = FRunnableThread::Create(RcData, TEXT("线程自定义"));
	}
}

void URobombGameInstance::ShutDown()
{
	Close();
	// 	if (RcData)
	// 	{
	// 		RcData->Stop();
	// 	}
	// 
	if (Threadl)
	{
		Threadl->Suspend(true);
		Threadl->Kill(false);
		delete Threadl;
		Threadl = nullptr;
	}
}

void URobombGameInstance::Close()
{
	SerialPort.Close();
}

bool URobombGameInstance::Open(int Port, int BaudRate)
{
	if (!SerialPort.Open(Port, BaudRate))
	{
		return false;
	}
	else
	{
		return true;
	}
}

void URobombGameInstance::OPEN_COM()
{
	system("D:\\project\\test\\mavlink.bat");
}

void URobombGameInstance::InitData()
{
	ModeOpera = ModeOperation::AmericaModeOoperation;
}
