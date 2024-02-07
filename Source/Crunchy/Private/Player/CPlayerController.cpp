// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/CPlayerController.h"
#include "Player/CPlayerCharacter.h"
#include "Widgets/GameplayUI.h"

void ACPlayerController::OnPossess(APawn* NewPawn)
{
	Super::OnPossess(NewPawn);
	if (HasAuthority())
	{
		UE_LOG(LogTemp, Warning, TEXT("On Possess Called on Server"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("On Possess Called on Client"));
	}
	PostPossessionSetup(NewPawn);
}

void ACPlayerController::AcknowledgePossession(APawn* NewPawn)
{
	Super::AcknowledgePossession(NewPawn);
	if (HasAuthority())
	{
		UE_LOG(LogTemp, Warning, TEXT("Ack called on Server"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Ack called on Client"));
	}
	PostPossessionSetup(NewPawn);
}

void ACPlayerController::PostPossessionSetup(APawn* NewPawn)
{
	PlayerCharacter = Cast<ACPlayerCharacter>(NewPawn);
	if (!PlayerCharacter)
	{
		UE_LOG(LogTemp, Error, TEXT("Needs CPlayerCharacter as Pawn"));
		return;
	}

	PlayerCharacter->SetupAbilitySystemComponent();
	SpawnGameplayUI();
	PlayerCharacter->InitAbilityAndAttribute();
}

void ACPlayerController::SpawnGameplayUI()
{
	if (!PlayerCharacter)
	{
		return;
	}

	if (!GameplayUIClass)
	{
		UE_LOG(LogTemp, Error, TEXT("%s, missing Gameplay UI class, Can't spawn gameplay UI"), *GetName());
		return;
	}
	//Returns true, if this player controller represents a human player sitting in front of this machine.
	if (IsLocalPlayerController())
	{
		return;
	}

	GameplayUI = CreateWidget<UGameplayUI>(this, GameplayUIClass);
	if (GameplayUI)
	{
		GameplayUI->AddToViewport();
	}
}

