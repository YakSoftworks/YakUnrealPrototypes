// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ProtoGenericPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;

struct FInputActionValue;

/**
 * 
 * The Generic Prototype Player Controller 
 * is meant to be substituable into any Prototype 
 * that is not PC dependant
 * 
 */
UCLASS()
class YAKUNREALPROTOTYPE_API AProtoGenericPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	AProtoGenericPlayerController();

protected:

#pragma region Input

	void SetupInputComponent();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputMappingContext> DefaultMappingContext;

#pragma region Input Actions

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> LookAction;

	//Sensitivity
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	float ControlSensitivity = 1;

#pragma endregion

#pragma region Input Functions

	void MoveEvent(const FInputActionValue& value);

	void LookEvent(const FInputActionValue& value);

#pragma endregion

#pragma endregion

	
};
