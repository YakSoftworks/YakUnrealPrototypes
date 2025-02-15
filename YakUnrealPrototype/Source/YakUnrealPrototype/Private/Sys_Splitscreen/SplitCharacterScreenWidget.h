// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SplitCharacterScreenWidget.generated.h"


class UImage;
/**
 * 
 */
UCLASS()
class YAKUNREALPROTOTYPE_API USplitCharacterScreenWidget : public UUserWidget
{
	GENERATED_BODY()

protected:

	virtual void NativeConstruct() override;

	void SetupPlayerImage(int playerIndex, UImage* displayReference);

	UPROPERTY(EditDefaultsOnly, meta=(BindWidget))
	TObjectPtr<UImage> CameraImage;
	
};
