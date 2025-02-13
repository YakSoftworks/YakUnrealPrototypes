// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SplitCharacterGamemode.generated.h"

class UTextureRenderTarget2D;
/**
 * 
 */
UCLASS()
class YAKUNREALPROTOTYPE_API ASplitCharacterGamemode : public AGameModeBase
{
	GENERATED_BODY()

	ASplitCharacterGamemode();

	virtual void BeginPlay() override;
	
public:

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UTextureRenderTarget2D> PlayerACameraTarget;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UTextureRenderTarget2D> PlayerBCameraTarget;
	

	
	
};
