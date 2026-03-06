// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Player/BomMainCharacterBase.h"

#include "GameFramework/CharacterMovementComponent.h"

ABomMainCharacterBase::ABomMainCharacterBase()
{
	GaitSettings.Add(UGaitEnums::Walking, FGaitSettings(300.0f, 1024.0f));
	GaitSettings.Add(UGaitEnums::Jogging, FGaitSettings(600.0f, 2048.0f));
	UpdateGait(UGaitEnums::Walking);
}

void ABomMainCharacterBase::RotateCharacterTowardCursor(const FVector& LookAtLocation)
{
	FVector LookAtVector = LookAtLocation - GetActorLocation();
	FRotator TargetRotation = FRotator(0, LookAtVector.Rotation().Yaw, 0);
	FRotator InterpRotation = FMath::RInterpTo(GetActorRotation(), TargetRotation, 1.0f, 0.2f);
	SetActorRotation(InterpRotation);
}

void ABomMainCharacterBase::UpdateGait(UGaitEnums DesiredGait)
{
	CurrentGait = DesiredGait;
	PreviousGait = CurrentGait;
	
	FGaitSettings* DesiredSettings = GaitSettings.Find(DesiredGait);
	
	if (UCharacterMovementComponent* MovementComponent = GetCharacterMovement())
	{
		MovementComponent->MaxWalkSpeed = DesiredSettings->MaxWalkSpeed;
		MovementComponent->MaxAcceleration = DesiredSettings->MaxAccelerationSpeed;
	}
}

void ABomMainCharacterBase::SetLocomotionState(ULocomotionStateEnums DesiredState)
{
	LocomotionState = DesiredState;
	UE_LOG(LogTemp, Warning, TEXT("SetLocomotionState - %hhd"), LocomotionState);
}
