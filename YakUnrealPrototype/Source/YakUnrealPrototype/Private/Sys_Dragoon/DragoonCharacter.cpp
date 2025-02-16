// Fill out your copyright notice in the Description page of Project Settings.


#include "Sys_Dragoon/DragoonCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Sys_Dragoon/DragoonAbilityComponent.h"
#include "DragoonEquipmentComponent.h"

// Sets default values
ADragoonCharacter::ADragoonCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpringArm"));
	CameraSpringArm->SetupAttachment(RootComponent);
	CameraSpringArm->TargetArmLength = 700.f;

	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	PlayerCamera->SetupAttachment(CameraSpringArm, USpringArmComponent::SocketName);

	PlayerAbilities = CreateDefaultSubobject<UDragoonAbilityComponent>(TEXT("PlayerAbilities"));

	PlayerEquipment = CreateDefaultSubobject<UDragoonEquipmentComponent>(TEXT("PlayerEquipment"));
	
}

void ADragoonCharacter::SetupWeapons()
{
	PlayerEquipment->SpawnWeapons();
}



void ADragoonCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	
}

// Called when the game starts or when spawned
void ADragoonCharacter::BeginPlay()
{
	Super::BeginPlay();
	PlayerEquipment->SpawnWeapons();
	
}

// Called every frame
void ADragoonCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADragoonCharacter::PerformAttack(EAttackDirection direction)
{
	switch (direction) {
	case EAttackDirection::Up:{
		UE_LOG(LogActor, Warning, TEXT("Attacking UP"));
		break;
		}

	case EAttackDirection::Down:{
		UE_LOG(LogActor, Warning, TEXT("Attacking DOWN"));
		break;
		}

	case EAttackDirection::Left:{
		UE_LOG(LogActor, Warning, TEXT("Attacking LEFT"));
		break;
		}

	case EAttackDirection::Right:{
		UE_LOG(LogActor, Warning, TEXT("Attacking RIGHT"));
		break;
		}

	}
}

