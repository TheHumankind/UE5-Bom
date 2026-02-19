// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Player/BomMainCharacterBase.h"

void ABomMainCharacterBase::RotateCharacterTowardCursor(const FVector& LookAtLocation)
{
	FVector LookAtVector = LookAtLocation - GetActorLocation();
	FRotator TargetRotation = FRotator(0, LookAtVector.Rotation().Yaw, 0);
	FRotator InterpRotation = FMath::RInterpTo(GetActorRotation(), TargetRotation, 2.0f, 0.2f);
	SetActorRotation(InterpRotation);
}
