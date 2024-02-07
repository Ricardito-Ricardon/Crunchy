// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ACPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	//This function calls only on the server
	virtual void OnPossess(APawn* NewPawn) override;

	//This function calls on both the listening server, and the client.
	virtual void AcknowledgePossession(APawn* NewPawn) override;

private:
	void PostPossessionSetup(APawn * NewPawn);

	void SpawnGameplayUI();

	UPROPERTY()
	class ACPlayerCharacter* PlayerCharacter;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<class UGameplayUI> GameplayUIClass;

	UPROPERTY()
	UGameplayUI* GameplayUI;
};
