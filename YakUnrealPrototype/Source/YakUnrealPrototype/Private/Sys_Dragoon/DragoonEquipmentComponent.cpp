// Fill out your copyright notice in the Description page of Project Settings.


#include "Sys_Dragoon/DragoonEquipmentComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DragoonPlayerController.h"
#include "DragoonPlayerState.h"
#include "DragoonCharacter.h"
#include "DragoonWeapon.h"

// Sets default values for this component's properties
UDragoonEquipmentComponent::UDragoonEquipmentComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDragoonEquipmentComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


void UDragoonEquipmentComponent::SpawnWeapons()
{
	if (!GetOwner()->HasAuthority()) { return; }
	if(ADragoonCharacter* owner = Cast<ADragoonCharacter>(GetOwner()))
	{
		ADragoonPlayerState* ps = Cast<ADragoonPlayerState>(owner->GetPlayerState());
		if (!ps) 
		{ 
			UE_LOG(LogActor, Warning, TEXT("Player State Invalid"));
			return; 
		}
		//If the ID is not null
		if (ps->RightHandWeaponID != FName("")) {

			UE_LOG(LogActor, Warning, TEXT("Spawning Right Weapon"));
			FActorSpawnParameters SpawnInfo;
			SpawnInfo.Owner = GetOwner();
			SpawnInfo.Instigator = Cast<APawn>(GetOwner());
			SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

			const FVector SpawnLocation = GetOwner()->GetActorLocation();
			const FRotator SpawnRotation = GetOwner()->GetActorRotation();

			//Then spawn in a weapon
			RightWeapon = GetWorld()->SpawnActor<ADragoonWeapon>(WeaponClass, SpawnLocation, SpawnRotation, SpawnInfo);

			//Set The Weapon Attachment
			RightWeapon->AttachToComponent(owner->GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, RightHandWeaponSocketID);

			//Setup the Weapon
			RightWeapon->SetupWeapon(ps->RightHandWeaponID);

		}
		if (!RightWeapon->IsTwoHanded()) {
			if (ps->LeftHandWeaponID != FName("")) {
				UE_LOG(LogActor, Warning, TEXT("Spawning Left Weapon"));
				FActorSpawnParameters SpawnInfo;
				SpawnInfo.Owner = GetOwner();
				SpawnInfo.Instigator = Cast<APawn>(GetOwner());
				SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

				const FVector SpawnLocation = GetOwner()->GetActorLocation();
				const FRotator SpawnRotation = GetOwner()->GetActorRotation();

				//Then spawn in a weapon
				RightWeapon = GetWorld()->SpawnActor<ADragoonWeapon>(WeaponClass, SpawnLocation, SpawnRotation, SpawnInfo);

				//Set The Weapon Attachment
				RightWeapon->AttachToComponent(owner->GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, LeftHandWeaponSocketID);

				//Setup the Weapon
				RightWeapon->SetupWeapon(ps->RightHandWeaponID);

			}
		}
	}

}

// Called every frame
void UDragoonEquipmentComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

