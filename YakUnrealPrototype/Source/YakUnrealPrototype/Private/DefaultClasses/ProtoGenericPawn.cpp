// Fill out your copyright notice in the Description page of Project Settings.


#include "DefaultClasses/ProtoGenericPawn.h"
#include "Components/StaticMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/PawnMovementComponent.h"

// Sets default values
AProtoGenericPawn::AProtoGenericPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	objectCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ObjectCamera"));
	objectCamera->SetupAttachment(GetMesh());

}

// Called when the game starts or when spawned
void AProtoGenericPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProtoGenericPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


