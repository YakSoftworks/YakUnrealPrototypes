// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SplitCharacter.generated.h"

class USceneCaptureComponent2D;

UCLASS()
class ASplitCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASplitCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Components")
	TObjectPtr<USceneCaptureComponent2D> SceneCapture;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


};
