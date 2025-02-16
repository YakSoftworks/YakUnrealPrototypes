// Fill out your copyright notice in the Description page of Project Settings.


#include "Sys_Dragoon/DragoonAbilityComponent.h"

// Sets default values for this component's properties
UDragoonAbilityComponent::UDragoonAbilityComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

bool UDragoonAbilityComponent::UseAbilityOne()
{
	UE_LOG(LogActor, Warning, TEXT("Using Ability One"));
	return false;
}

bool UDragoonAbilityComponent::UseAbilityTwo()
{
	UE_LOG(LogActor, Warning, TEXT("Using Ability Two"));
	return false;
}

bool UDragoonAbilityComponent::UseAbilityThree()
{
	UE_LOG(LogActor, Warning, TEXT("Using Ability Three"));
	return false;
}


// Called when the game starts
void UDragoonAbilityComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UDragoonAbilityComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

