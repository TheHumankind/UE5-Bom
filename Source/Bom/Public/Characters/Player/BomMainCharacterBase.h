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
	void RotateCharacterTowardCursor(const FVector& LookAtLocation);

	UFUNCTION(BlueprintCallable)
	void Disarm() { CurrentGait = ULocomotionStateEnums::Unarmed; };

	UFUNCTION(BlueprintCallable)
	void Arm() { CurrentGait = ULocomotionStateEnums::Armed; };

	UFUNCTION(BlueprintCallable)
	ULocomotionStateEnums GetGait() const { return CurrentGait; };

private:
	UPROPERTY()
	ULocomotionStateEnums CurrentGait = ULocomotionStateEnums::Unarmed;

	UPROPERTY()
	TMap<ULocomotionStateEnums, FGaitSettings> GaitSettings;
	
};
