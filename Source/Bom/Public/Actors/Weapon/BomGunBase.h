// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BomGunBase.generated.h"

UCLASS()
class BOM_API ABomGunBase : public AActor
{
	GENERATED_BODY()
	
public:	
	ABomGunBase();

protected:
	virtual void BeginPlay() override;
	

};
