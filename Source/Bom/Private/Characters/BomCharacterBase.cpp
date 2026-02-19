// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/BomCharacterBase.h"

// Sets default values
ABomCharacterBase::ABomCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABomCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABomCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABomCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

