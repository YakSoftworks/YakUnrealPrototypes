// Fill out your copyright notice in the Description page of Project Settings.


#include "Sys_Dragoon/DragoonWeapon.h"


// Sets default values
ADragoonWeapon::ADragoonWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ObjectRoot = CreateDefaultSubobject<USceneComponent>(TEXT("ObjectRoot"));
	SetRootComponent(ObjectRoot);

	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh"));
	WeaponMesh->SetupAttachment(RootComponent);

}

void ADragoonWeapon::SetupWeapon(FName newWeaponID)
{
	weaponID = newWeaponID;

	SetWeaponData();
	

}

void ADragoonWeapon::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	SetWeaponData();
}

// Called when the game starts or when spawned
void ADragoonWeapon::BeginPlay()
{
	Super::BeginPlay();

	if (weaponID != FName("")) {
		SetWeaponData();
	}
	
}

void ADragoonWeapon::SetWeaponData()
{
	FDragoonWeaponRow* data = WeaponDataTable->FindRow<FDragoonWeaponRow>(weaponID, "", false);
	WeaponData = *data;

	WeaponMesh->SetSkeletalMesh(WeaponData.weaponMesh);
	//WeaponMesh->SetRelativeTransform(WeaponData.WeaponSocketOffset);
	
	
}

// Called every frame
void ADragoonWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

