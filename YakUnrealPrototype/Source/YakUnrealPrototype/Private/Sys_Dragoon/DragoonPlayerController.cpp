// Fill out your copyright notice in the Description page of Project Settings.


#include "Sys_Dragoon/DragoonPlayerController.h"
#include "Sys_Dragoon/DragoonCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

ADragoonPlayerController::ADragoonPlayerController()
{
	

}

void ADragoonPlayerController::OnPossess(APawn* pawn)
{
	Super::OnPossess(pawn);

	//Keep a reference to our character so that we don't have to repeatedly cast
	if (ADragoonCharacter* character = Cast<ADragoonCharacter>(pawn)) {
		possessedDragoon = character;
	}
}

void ADragoonPlayerController::OnUnPossess()
{
	Super::OnUnPossess();

	if (possessedDragoon) { possessedDragoon = nullptr; }
}

void ADragoonPlayerController::BeginPlayingState()
{
	Super::BeginPlayingState();
	if (possessedDragoon) {
		possessedDragoon->SetupWeapons();
	}
}

void ADragoonPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer())) {

		Subsystem->AddMappingContext(DragoonMappingContext, 0);
	}

	if (UEnhancedInputComponent* EnhancedComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		//Move/Look
		EnhancedComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ADragoonPlayerController::MoveEvent);
		EnhancedComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ADragoonPlayerController::LookEvent);

		//Jump
		EnhancedComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ADragoonPlayerController::JumpEvent);
		EnhancedComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ADragoonPlayerController::StopJumpingEvent);

		//Attack
		EnhancedComponent->BindAction(AttackAction, ETriggerEvent::Started, this, &ADragoonPlayerController::AttackEvent);
	
		//Use Abilities
		EnhancedComponent->BindAction(UseAbilityOneAction, ETriggerEvent::Started, this, &ADragoonPlayerController::UseAbilityOneEvent);
		EnhancedComponent->BindAction(UseAbilityTwoAction, ETriggerEvent::Started, this, &ADragoonPlayerController::UseAbilityTwoEvent);
		EnhancedComponent->BindAction(UseAbilityThreeAction, ETriggerEvent::Started, this, &ADragoonPlayerController::UseAbilityThreeEvent);

	}
}

void ADragoonPlayerController::MoveEvent(const FInputActionValue& value)
{
	//UE_LOG(LogActor, Warning, TEXT("CHARACTER MOVING"));
	if (!GetPawn()) { return; }

	FVector2D MoveInput = value.Get<FVector2D>();

	const FRotator Rotation = GetControlRotation();

	const FRotator YawRotation(0, Rotation.Yaw, 0);

	const FVector ForwardVector = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightVector = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	GetPawn()->AddMovementInput(ForwardVector, MoveInput.Y);
	GetPawn()->AddMovementInput(RightVector, MoveInput.X);

}

void ADragoonPlayerController::JumpEvent(const FInputActionValue& value)
{
	if (possessedDragoon) {
		possessedDragoon->Jump();
	}
}

void ADragoonPlayerController::StopJumpingEvent(const FInputActionValue& value)
{
	if (possessedDragoon) {
		possessedDragoon->StopJumping();
	}
}

void ADragoonPlayerController::LookEvent(const FInputActionValue& value)
{
	//UE_LOG(LogActor, Warning, TEXT("CHARACTER LOOKING"));
	if (!GetPawn()) { return; }

	LastLookDirection = value.Get<FVector2D>();

	ControlRotation.Yaw += (LastLookDirection.X * lookSensitivity);
	ControlRotation.Pitch -= (LastLookDirection.Y * lookSensitivity);

	LastLookDirection.Normalize();
}

void ADragoonPlayerController::AttackEvent(const FInputActionValue& value)
{
	UE_LOG(LogActor, Warning, TEXT("CHARACTER ATTACKING"));
	if (possessedDragoon) {

		//Decide Vertical/Horizontal
		if (FMath::Abs(LastLookDirection.X) >= FMath::Abs(LastLookDirection.Y)) 
		{ //Horizontal
			
			if (FMath::Sign(LastLookDirection.X) > 0) { //Decide Left/Right
				//Right
				possessedDragoon->PerformAttack(EAttackDirection::Right);
			}
			else
			{
				//Left
				possessedDragoon->PerformAttack(EAttackDirection::Left);
			}
		} else 
		{ //Vertical
			if (FMath::Sign(LastLookDirection.Y) > 0) { //Decide Up/Down
				//Right
				possessedDragoon->PerformAttack(EAttackDirection::Up);
			}
			else
			{
				//Left
				possessedDragoon->PerformAttack(EAttackDirection::Down);
			}
		}
	}
}

void ADragoonPlayerController::UseAbilityOneEvent(const FInputActionValue& value)
{
	if (possessedDragoon) {
		possessedDragoon->GetPlayerAbilities()->UseAbilityOne();
	}
}

void ADragoonPlayerController::UseAbilityTwoEvent(const FInputActionValue& value)
{
	if (possessedDragoon) {
		possessedDragoon->GetPlayerAbilities()->UseAbilityTwo();
	}
}

void ADragoonPlayerController::UseAbilityThreeEvent(const FInputActionValue& value)
{
	if (possessedDragoon) {
		possessedDragoon->GetPlayerAbilities()->UseAbilityThree();
	}
}
