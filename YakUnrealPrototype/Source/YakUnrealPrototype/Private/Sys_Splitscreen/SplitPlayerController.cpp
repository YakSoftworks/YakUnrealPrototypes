// Fill out your copyright notice in the Description page of Project Settings.


#include "SplitPlayerController.h"

#include "SplitCharacter.h"

void ASplitPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	if(ASplitPlayerController* pc = Cast<ASplitPlayerController>(GetLocalPlayer()->GetPlayerController(GetWorld())))
	{
		pc->CreateCameraWidget();
	}
}

UTextureRenderTarget2D* ASplitPlayerController::GetCharacterRenderTarget() const
{
	if(ASplitCharacter* character = Cast<ASplitCharacter>(GetCharacter()))
	{
		return character->GetRenderTarget();
	}
	return nullptr;
}

void ASplitPlayerController::CreateCameraWidget_Implementation()
{

	playerCameraWidget = CreateWidget<USplitCharacterScreenWidget>(this, playerCameraWidgetClass);
	playerCameraWidget->SetOwningLocalPlayer(GetLocalPlayer());
	playerCameraWidget->AddToViewport();
}
