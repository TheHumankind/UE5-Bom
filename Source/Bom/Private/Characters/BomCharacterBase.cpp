// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/BomCharacterBase.h"

ABomCharacterBase::ABomCharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ABomCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABomCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABomCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

