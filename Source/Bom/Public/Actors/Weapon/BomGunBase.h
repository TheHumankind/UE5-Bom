// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enum/AnimationEnums.h"
#include "GameFramework/Actor.h"
#include "BomGunBase.generated.h"

UCLASS(BlueprintType)
class BOM_API ABomGunBase : public AActor
{
	GENERATED_BODY()
	
public:	
	ABomGunBase();

	ULocomotionStateEnums GetGunState() const { return GunAnimationState; }

	void Shoot(const FVector* ShootDirection, const UMeshComponent* ShooterMesh);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Gun")                                             
	ULocomotionStateEnums GunAnimationState = ULocomotionStateEnums::Unarmed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Gun")                           
	UAnimMontage* GunAnimationMontage;

protected:
	
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	USceneComponent* Root;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Mesh;
	



	
	
};
