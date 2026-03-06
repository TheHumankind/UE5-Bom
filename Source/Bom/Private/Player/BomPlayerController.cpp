// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/BomPlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Characters/Player/BomMainCharacterBase.h"

void ABomPlayerController::BeginPlay()
{
	Super::BeginPlay();

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	Subsystem->AddMappingContext(PlayerMappingContext, 0);

	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);

	MainCharacter = CastChecked<ABomMainCharacterBase>(GetPawn());
}

void ABomPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	CursorTrace();
}

void ABomPlayerController::CursorTrace()
{
	if (MainCharacter)
	{
		FHitResult CursorHit;

		GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
		DrawDebugSphere(GetWorld(), CursorHit.Location, 16, 32, FColor::Green);

		MainCharacter->RotateCharacterTowardCursor(CursorHit.Location);
	}
}

void ABomPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ABomPlayerController::Move);
	EnhancedInputComponent->BindAction(JogAction, ETriggerEvent::Started, this, &ABomPlayerController::Jog);
	EnhancedInputComponent->BindAction(JogAction, ETriggerEvent::Completed, this, &ABomPlayerController::Jog);
	EnhancedInputComponent->BindAction(EndlessJogAction, ETriggerEvent::Started, this, &ABomPlayerController::Jog);
	EnhancedInputComponent->BindAction(GetPrimaryGunAction, ETriggerEvent::Started, this, &ABomPlayerController::GetPrimaryGun);
	EnhancedInputComponent->BindAction(GetSecondaryGunAction, ETriggerEvent::Started, this, &ABomPlayerController::GetSecondaryGun);
	EnhancedInputComponent->BindAction(HideGunAction, ETriggerEvent::Started, this, &ABomPlayerController::HideGun);
}

void ABomPlayerController::Move(const struct FInputActionValue& ActionValue)
{
	const FVector2D InputAxisValue = ActionValue.Get<FVector2D>();
	const FRotator Rotation = MainCharacter->GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisValue.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisValue.X);
	}
}

void ABomPlayerController::Jog(const struct FInputActionValue& ActionValue)
{
	if (MainCharacter->GetGait() == UGaitEnums::Walking)
	{
		MainCharacter->UpdateGait(UGaitEnums::Jogging);
	}
	else if (MainCharacter->GetGait() == UGaitEnums::Jogging)
	{
		MainCharacter->UpdateGait(UGaitEnums::Walking);
	}
}

void ABomPlayerController::GetPrimaryGun(const struct FInputActionValue& ActionValue)
{
	UE_LOG(LogTemp, Warning, TEXT("Primary"));
	MainCharacter->SetLocomotionState(ULocomotionStateEnums::Rifle);
}

void ABomPlayerController::GetSecondaryGun(const struct FInputActionValue& ActionValue)
{
	UE_LOG(LogTemp, Error, TEXT("Secondary"));
	MainCharacter->SetLocomotionState(ULocomotionStateEnums::Pistol);
}

void ABomPlayerController::HideGun(const struct FInputActionValue& ActionValue)
{
	UE_LOG(LogTemp, Error, TEXT("Hide Gun"));
	MainCharacter->SetLocomotionState(ULocomotionStateEnums::Unarmed);
}
