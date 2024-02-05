// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/CPlayerController.h"
#include "Player/CPlayerCharacter.h"

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
	//do some ui work
	PlayerCharacter->InitAbilityAndAttribute();
}

