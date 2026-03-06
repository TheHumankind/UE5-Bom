// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimationEnums.generated.h"

UENUM(BlueprintType)
enum class ULocomotionStateEnums :uint8
{
	Unarmed UMETA(DisplayName = "Unarmed"),
	Pistol UMETA(DisplayName = "Pistol"),
	Rifle UMETA(DisplayName = "Rifle"),
	Shotgun UMETA(DisplayName = "Shotgun"),
};

UENUM(BlueprintType)
enum class UGaitEnums : uint8
{
	Walking UMETA(DisplayName = "Walking"),
	Jogging  UMETA(DisplayName = "Jogging"),
};
