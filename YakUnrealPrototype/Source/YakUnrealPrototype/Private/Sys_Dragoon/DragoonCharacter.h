// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DragoonAbilityComponent.h"
#include "DragoonCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UDragoonEquipmentComponent;

UENUM()
enum EAttackDirection {
	Up,
	Down,
	Left,
	Right
};

UCLASS()
class ADragoonCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ADragoonCharacter();

	FORCEINLINE class UDragoonAbilityComponent* GetPlayerAbilities() const { return PlayerAbilities; }

	void SetupWeapons();

protected:

	void PostInitializeComponents() override;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	

	UPROPERTY(EditDefaultsOnly, Category="Components")
	TObjectPtr<USpringArmComponent> CameraSpringArm;

	UPROPERTY(EditDefaultsOnly, Category = "Components")
	TObjectPtr<UCameraComponent> PlayerCamera;

	UPROPERTY(EditDefaultsOnly, Category = "Components")
	TObjectPtr<UDragoonAbilityComponent> PlayerAbilities;

	UPROPERTY(EditDefaultsOnly, Category = "Components")
	TObjectPtr<UDragoonEquipmentComponent> PlayerEquipment;

	UPROPERTY()
	bool bIsAttacking = false;



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	void PerformAttack(EAttackDirection direction);


};


