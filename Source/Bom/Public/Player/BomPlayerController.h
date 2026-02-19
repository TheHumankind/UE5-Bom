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

protected:
	virtual void BeginPlay() override;

private:
	FInputModeGameAndUI InputModeData;
	void CursorTrace();
	virtual void SetupInputComponent() override;

	UPROPERTY(EditAnywhere, Category = "Input | IMC")
	TObjectPtr<UInputMappingContext> PlayerMappingContext;

	UPROPERTY(EditAnywhere, Category = "Input | Action")
	TObjectPtr<UInputAction> MoveAction;

	void Move(const struct FInputActionValue& ActionValue);
	
	
};
