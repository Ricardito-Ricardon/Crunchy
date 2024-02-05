// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/CCharacterCase.h"
#include "GameplayAbilities/CAbilitySystemComponent.h"
#include "GameplayAbilities/CAttributeSet.h"

// Sets default values
ACCharacterCase::ACCharacterCase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComponent = CreateDefaultSubobject<UCAbilitySystemComponent>("Ability System Component");
	AbilitySystemComponent->SetIsReplicated(true); // Replicate means it synced with the server
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject <UCAttributeSet>("Attribute Set");
}

void ACCharacterCase::SetupAbilitySystemComponent()
{
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}

void ACCharacterCase::InitAbilityAndAttribute()
{
	AbilitySystemComponent->ApplyInitialEffects();
}

// Called when the game starts or when spawned
void ACCharacterCase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACCharacterCase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACCharacterCase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{

}

UAbilitySystemComponent* ACCharacterCase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}