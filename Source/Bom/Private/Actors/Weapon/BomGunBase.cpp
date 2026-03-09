// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Weapon/BomGunBase.h"

ABomGunBase::ABomGunBase()
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);
	Mesh->SetupAttachment(Root);
}

void ABomGunBase::Shoot(const FVector* ShootDirection, const UMeshComponent* ShooterMesh)
{
	
}

void ABomGunBase::BeginPlay()
{
	Super::BeginPlay();
}

