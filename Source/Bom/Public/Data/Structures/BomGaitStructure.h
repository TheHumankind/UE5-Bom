// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BomGaitStructure.generated.h"

USTRUCT(BlueprintType)
struct FGaitSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gait Settings")
	float MaxWalkSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gait Settings")
	float MaxAcceleration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gait Settings")
	float BreakingDeceleration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gait Settings")
	float BrakingFrictionFactor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gait Settings")
	bool UseSeparateBreakingFriction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gait Settings")
	float BreakingFriction;
	
};