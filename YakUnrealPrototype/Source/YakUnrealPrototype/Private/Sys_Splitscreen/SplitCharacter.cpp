// Fill out your copyright notice in the Description page of Project Settings.


#include "Sys_Splitscreen/SplitCharacter.h"

#include "SplitCharacterGamemode.h"
#include "Components/SceneCaptureComponent2D.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ASplitCharacter::ASplitCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneCapture = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("SceneCapture"));
	SceneCapture->SetupAttachment(RootComponent);


}

UTextureRenderTarget2D* ASplitCharacter::GetRenderTarget() const
{

	return SceneCapture->TextureTarget;
	
}

void ASplitCharacter::SetRenderTarget(UTextureRenderTarget2D* target)
{
	SceneCapture->TextureTarget = target;
}

// Called when the game starts or when spawned
void ASplitCharacter::BeginPlay()
{
	Super::BeginPlay();
	 
	ACharacter* character = UGameplayStatics::GetPlayerCharacter(this, 0);
	if(character == this)
	{
		if(ASplitCharacterGamemode* gm = Cast<ASplitCharacterGamemode>(UGameplayStatics::GetGameMode(this)))
		{
			SceneCapture->TextureTarget = gm->PlayerACameraTarget;
			
		}
	}
	else
	{
		if(ASplitCharacterGamemode* gm = Cast<ASplitCharacterGamemode>(UGameplayStatics::GetGameMode(this)))
		{
			SceneCapture->TextureTarget = gm->PlayerBCameraTarget;
		}
	}
	
	
}

// Called every frame
void ASplitCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

