// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DragoonWeapon.generated.h"

class USkeletalMesh;
class UDataTable;

UENUM()
enum class EWeaponHoldType 
{
	OneHanded,
	TwoHanded
};

UENUM()
enum class EWeaponType
{
	SmallWeapon,
	LargeWeapon,
	Spear,
	Bow,
	Gun,
	Magic
};

USTRUCT(BlueprintType)
struct FWeaponStats
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, Category = "All")
	float WeaponStrength;

};

USTRUCT()
struct FDragoonWeaponRow : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, Category = "Appearance")
	TObjectPtr<USkeletalMesh> weaponMesh;

	UPROPERTY(EditDefaultsOnly, Category = "Appearance")
	FTransform WeaponSocketOffset;

	UPROPERTY(EditDefaultsOnly, Category = "Appearance")
	EWeaponType WeaponType;

	UPROPERTY(EditDefaultsOnly, Category = "Appearance")
	EWeaponHoldType WeaponHold;

#pragma region Stats
	UPROPERTY(EditDefaultsOnly, Category = "Stats")
	FWeaponStats stats;

#pragma endregion

};



UCLASS()
class ADragoonWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADragoonWeapon();

	void SetupWeapon(FName newWeaponID);

protected:

	void PostInitializeComponents() override;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Weapon")
	FName weaponID;

	UPROPERTY(EditDefaultsOnly, Category = "Components")
	TObjectPtr<USceneComponent> ObjectRoot;

	UPROPERTY(EditDefaultsOnly, Category = "Components")
	TObjectPtr<USkeletalMeshComponent> WeaponMesh;

	UPROPERTY(VisibleAnywhere, Category = "Weapon")
	FDragoonWeaponRow WeaponData;

	UPROPERTY(EditDefaultsOnly, Category = "GeneralWeapon")
	TObjectPtr<UDataTable> WeaponDataTable;

	void SetWeaponData();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FORCEINLINE bool IsTwoHanded() const { return WeaponData.WeaponHold == EWeaponHoldType::TwoHanded; }

};
