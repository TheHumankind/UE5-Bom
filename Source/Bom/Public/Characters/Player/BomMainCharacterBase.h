// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/BomCharacterBase.h"
#include "Enum/AnimationEnums.h"
#include "Data/Structures/BomGaitStructure.h"
#include "BomMainCharacterBase.generated.h"

struct FGaitSettings;
enum class ULocomotionStateEnums : uint8;

UCLASS()
class BOM_API ABomMainCharacterBase : public ABomCharacterBase
{
	GENERATED_BODY()
	
	
public:
	ABomMainCharacterBase();
	
	void RotateCharacterTowardCursor(const FVector& LookAtLocation);



	UFUNCTION(BlueprintCallable)
	UGaitEnums GetGait() const { return CurrentGait; };

	UFUNCTION(BlueprintCallable)
	void UpdateGait(UGaitEnums DesiredGait);

	ULocomotionStateEnums GetLocomotionState() const { return LocomotionState; };

	UFUNCTION(BlueprintCallable)
	void SetLocomotionState(ULocomotionStateEnums DesiredState);

private:
	
	UPROPERTY()
	UGaitEnums CurrentGait = UGaitEnums::Walking;

	UPROPERTY()
	UGaitEnums PreviousGait;

	UPROPERTY()
	TMap<UGaitEnums, FGaitSettings> GaitSettings;

	UPROPERTY()
	ULocomotionStateEnums LocomotionState = ULocomotionStateEnums::Unarmed;
	
};
