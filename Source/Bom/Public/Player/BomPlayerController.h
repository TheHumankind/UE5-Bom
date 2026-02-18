// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BomPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
/**
 * 
 */
UCLASS()
class BOM_API ABomPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, Category = "Input | Action")
	UInputAction* MoveInputAction;

	UPROPERTY(EditAnywhere, Category = "Input | Action")
	UInputAction* ShootInputAction;

	UPROPERTY(EditAnywhere, Category = "Input | IMC")
	UInputMappingContext* PlayerMappingContext;

protected:
	virtual void BeginPlay() override;
	
};
