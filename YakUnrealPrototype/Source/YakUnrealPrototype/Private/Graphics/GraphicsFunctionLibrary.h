// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GraphicsFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class UGraphicsFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	//NOTE: ALL FUNCTIONS HERE SHOULD BE STATIC UFUNCTION(BLUEPRINTCALLABLE)
	
public:
	// Get the standard reflectance of the pigment with infinite thickness
	UFUNCTION(BlueprintPure, Category="Pigments")
	static FVector GetKubelkaInfiniteReflectance(FVector S, FVector K); 
	
};
