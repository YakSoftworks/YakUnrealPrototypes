// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ProtoGenericPlayerController.generated.h"

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

	
};
