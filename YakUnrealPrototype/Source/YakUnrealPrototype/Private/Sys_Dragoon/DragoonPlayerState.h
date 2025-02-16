// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "DragoonPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class ADragoonPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	ADragoonPlayerState();

	UPROPERTY(EditDefaultsOnly, Category = "Equipment|Armor")
	FName HeadArmorID;

	UPROPERTY(EditDefaultsOnly, Category = "Equipment|Armor")
	FName ChestArmorID;

	UPROPERTY(EditDefaultsOnly, Category = "Equipment|Armor")
	FName LegArmorID;

	UPROPERTY(EditDefaultsOnly, Category = "Equipment|Armor")
	FName FootArmorID;

	UPROPERTY(EditDefaultsOnly, Category = "Equipment|Weapon")
	FName LeftHandWeaponID;

	UPROPERTY(EditDefaultsOnly, Category = "Equipment|Weapon")
	FName RightHandWeaponID;

	
	
};
