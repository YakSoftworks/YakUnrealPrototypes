// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "DragoonPlayerController.generated.h"

class UInputMappingContext; //Unreal Input Mapping Context
class UInputAction; //Unreal Input Action
class ADragoonCharacter;

struct FInputActionValue; //Contains values of input action
/**
 * 
 */
UCLASS()
class ADragoonPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	ADragoonPlayerController();

protected:

	void OnPossess(APawn* pawn) override;

	void OnUnPossess() override;

	void BeginPlayingState() override;


	UPROPERTY()
	TObjectPtr<ADragoonCharacter> possessedDragoon;

#pragma region Input

	void SetupInputComponent() override;
	
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputMappingContext> DragoonMappingContext;

#pragma region Input Actions and Events

/*
* MoveAction - Standard move our character
*/

UPROPERTY(EditDefaultsOnly, Category = "Input")
TObjectPtr<UInputAction> MoveAction;

void MoveEvent(const FInputActionValue& value);

UPROPERTY(EditDefaultsOnly, Category = "Input")
TObjectPtr<UInputAction> JumpAction;

void JumpEvent(const FInputActionValue& value);
void StopJumpingEvent(const FInputActionValue& value);

UPROPERTY(EditDefaultsOnly, Category = "Input")
TObjectPtr<UInputAction> LookAction;

UPROPERTY(EditDefaultsOnly, Category = "Input")
float lookSensitivity = 1.f;

void LookEvent(const FInputActionValue& value);

UPROPERTY(EditDefaultsOnly, Category = "Input|Attack")
TObjectPtr<UInputAction> AttackAction;

void AttackEvent(const FInputActionValue& value);

UPROPERTY()
FVector2D LastLookDirection;

UPROPERTY(EditDefaultsOnly, Category = "Input|Attack|Abilities")
TObjectPtr<UInputAction> UseAbilityOneAction;

void UseAbilityOneEvent(const FInputActionValue& value);

UPROPERTY(EditDefaultsOnly, Category = "Input|Attack|Abilities")
TObjectPtr<UInputAction> UseAbilityTwoAction;

void UseAbilityTwoEvent(const FInputActionValue& value);

UPROPERTY(EditDefaultsOnly, Category = "Input|Attack|Abilities")
TObjectPtr<UInputAction> UseAbilityThreeAction;

void UseAbilityThreeEvent(const FInputActionValue& value);

#pragma endregion
	
};
