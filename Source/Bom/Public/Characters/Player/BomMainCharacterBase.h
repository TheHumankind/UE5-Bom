// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/BomCharacterBase.h"
#include "Enum/AnimationEnums.h"
#include "Data/Structures/BomGaitStructure.h"
#include "BomMainCharacterBase.generated.h"

class ABomGunBase;
struct FGaitSettings;
enum class ULocomotionStateEnums : uint8;

UCLASS(BlueprintType)
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

	UFUNCTION(BlueprintCallable)
	ULocomotionStateEnums GetLocomotionState() const { return LocomotionState; };

	UFUNCTION(BlueprintCallable)
	void SetLocomotionState(ULocomotionStateEnums DesiredState);

	UFUNCTION(BlueprintCallable)
	FVector GetLastLookAtLocation() const { return LastLookAtLocation; };

	UFUNCTION(BlueprintCallable)
	void SetSecondaryGun(TSubclassOf<ABomGunBase> NewSecondaryGun);

protected:
	virtual void Tick(float DeltaSeconds) override;
	

private:
	
	UPROPERTY()
	UGaitEnums CurrentGait = UGaitEnums::Walking;

	UPROPERTY()
	UGaitEnums PreviousGait;

	UPROPERTY()
	TMap<UGaitEnums, FGaitSettings> GaitSettings;

	UPROPERTY()
	ULocomotionStateEnums LocomotionState = ULocomotionStateEnums::Unarmed;

	UPROPERTY()
	ABomGunBase* SecondaryGun;

	UPROPERTY()
	FVector LastLookAtLocation = FVector::ZeroVector;
	
};
