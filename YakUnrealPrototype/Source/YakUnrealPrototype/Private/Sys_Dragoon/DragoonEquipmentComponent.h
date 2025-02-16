// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Components/ActorComponent.h"
#include "DragoonEquipmentComponent.generated.h"

class ADragoonWeapon;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UDragoonEquipmentComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDragoonEquipmentComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Equipment")
	TSubclassOf<ADragoonWeapon> WeaponClass;

	UPROPERTY(VisibleAnywhere, Category = "Equipment")
	TObjectPtr<ADragoonWeapon> LeftWeapon;

	UPROPERTY(VisibleAnywhere, Category = "Equipment")
	TObjectPtr<ADragoonWeapon> RightWeapon;

	UPROPERTY(EditDefaultsOnly, Category = "Equipment|SocketIDS")
	FName LeftHandWeaponSocketID;

	UPROPERTY(EditDefaultsOnly, Category = "Equipment|SocketIDS")
	FName RightHandWeaponSocketID;

	UPROPERTY(EditDefaultsOnly, Category = "Equipment|SocketIDS")
	FName HeadSocketID;



	


public:	

	void SpawnWeapons();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
