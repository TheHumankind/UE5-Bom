// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BomGaitStructure.generated.h"

USTRUCT(BlueprintType)
struct FGaitSettings
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Gait Settings", meta=(ClampMin="0.0"))
	float MaxWalkSpeed = 600.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Gait Settings", meta=(ClampMin="0.0"))
	float MaxAccelerationSpeed = 2048.0f;

	FGaitSettings() = default;
	
	FGaitSettings(float InMaxWalkSpeed, float InMaxAccelerationSpeed)
		: MaxWalkSpeed(InMaxWalkSpeed)
		, MaxAccelerationSpeed(InMaxAccelerationSpeed)
	{}
};

