// Fill out your copyright notice in the Description page of Project Settings.


#include "DefaultClasses/ProtoGenericPlayerController.h"
#include "DefaultClasses/ProtoGenericPawn.h"
#include "GameFramework/PawnMovementComponent.h"
#include "InputActionValue.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"


AProtoGenericPlayerController::AProtoGenericPlayerController()
{
}

void AProtoGenericPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer())) {

		Subsystem->AddMappingContext(DefaultMappingContext, 0);
	}

	if (UEnhancedInputComponent* EnhancedComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AProtoGenericPlayerController::MoveEvent);
		EnhancedComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AProtoGenericPlayerController::LookEvent);
	}

	

}

void AProtoGenericPlayerController::MoveEvent(const FInputActionValue& value)
{
	if (!GetPawn()) { return; }

	FVector2D MoveInput = value.Get<FVector2D>();

	const FRotator Rotation = GetControlRotation();

	const FRotator YawRotation(0, Rotation.Yaw, 0);

	const FVector ForwardVector = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightVector = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	GetPawn()->AddMovementInput(ForwardVector, MoveInput.Y);
	GetPawn()->AddMovementInput(RightVector, MoveInput.X);
}

void AProtoGenericPlayerController::LookEvent(const FInputActionValue& value)
{
	if (!GetPawn()) { return; }

	FVector2D LookInput = value.Get<FVector2D>();

	ControlRotation.Yaw += (LookInput.X * ControlSensitivity);
	ControlRotation.Pitch -= (LookInput.Y * ControlSensitivity);


}
