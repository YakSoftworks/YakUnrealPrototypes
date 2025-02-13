// Fill out your copyright notice in the Description page of Project Settings.


#include "SplitCharacterScreenWidget.h"
#include "Kismet/GameplayStatics.h"
#include "SplitCharacterGamemode.h"
#include "SplitPlayerController.h"
#include "Components/Image.h"
#include "Engine/TextureRenderTarget2D.h"

void USplitCharacterScreenWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
	
}

void USplitCharacterScreenWidget::SetupPlayerImage(int playerIndex, UImage* displayReference)
{
	if(ASplitPlayerController* pc = Cast<ASplitPlayerController>
		(UGameplayStatics::GetPlayerController(this, 0)))
	{
		FString objectName = "PlayerRenderTexture" + FString::FromInt(playerIndex);
		displayReference->SetBrushFromTexture(pc->GetCharacterRenderTarget()->ConstructTexture2D(this, objectName, RF_Transient));
	}
	
}
