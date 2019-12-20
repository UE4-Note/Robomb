// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "RoboBarsMain.generated.h"


UCLASS()
class ROBOMB_API ARoboBarsMain : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ARoboBarsMain();
	~ARoboBarsMain();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

/*================ Tom 2019/12/20 ===================*/

public:
 
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly , Category = "Mesh")
 		class USkeletalMeshComponent* SKeletalMeshComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly , Category = "Mesh")
		class UPostProcessComponent* PostProcessComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly , Category = "Mesh")
		class USpringArmComponent* SpringArmComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly , Category = "Mesh")
		class UCameraComponent* CameraComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly , Category = "Mesh")
		class UWidgetComponent* WidgetComp;
	
private:

	const class URobombGameInstance* GameInstace;

};