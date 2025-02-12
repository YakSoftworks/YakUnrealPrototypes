// Fill out your copyright notice in the Description page of Project Settings.


#include "Sys_Splitscreen/SplitCharacter.h"
#include "Components/SceneCaptureComponent2D.h"

// Sets default values
ASplitCharacter::ASplitCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneCapture = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("SceneCapture"));
	SceneCapture->SetupAttachment(RootComponent);


}

// Called when the game starts or when spawned
void ASplitCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASplitCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

