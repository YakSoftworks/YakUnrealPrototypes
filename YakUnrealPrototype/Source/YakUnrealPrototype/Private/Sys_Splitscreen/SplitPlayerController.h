// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SplitCharacterScreenWidget.h"
#include "DefaultClasses/ProtoGenericPlayerController.h"
#include "SplitPlayerController.generated.h"


class UTextureRenderTarget2D;

/**
 * 
 */
UCLASS()
class YAKUNREALPROTOTYPE_API ASplitPlayerController : public AProtoGenericPlayerController
{
	GENERATED_BODY()
public:

	virtual void BeginPlay() override;
	
	UTextureRenderTarget2D* GetCharacterRenderTarget() const;

protected:

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USplitCharacterScreenWidget> playerCameraWidget;

	UPROPERTY(EditDefaultsOnly, Category= "UI")
	TSubclassOf<UUserWidget> playerCameraWidgetClass;

	UFUNCTION(Client, Reliable)
	void CreateCameraWidget();
};
