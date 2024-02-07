// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/CCharacterCase.h"
#include "GameplayAbilities/CAbilitySystemComponent.h"
#include "GameplayAbilities/CAttributeSet.h"
#include "Widgets/StatusGauge.h"
#include "Components/Widgetcomponent.h"

// Sets default values
ACCharacterCase::ACCharacterCase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComponent = CreateDefaultSubobject<UCAbilitySystemComponent>("Ability System Component");
	AbilitySystemComponent->SetIsReplicated(true); // Replicate means it synced with the server
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject <UCAttributeSet>("Attribute Set");

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UCAttributeSet::GetHealthAttribute()).AddObject(this, &ACCharacterCase:HealthUpdated);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UCAttributeSet::GetMaxHealthAttribute()).AddObject(this, &ACCharacterCase:MaxHealthUpdated);

	StatusWidgetComp = CreateDefaultSubobject<UWidgetComponent>("Status Widget Comp");
	StatusWidgetComp->SetupAttatchment(GetRootComponent());
}

void ACCharacterCase::SetupAbilitySystemComponent()
{
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}

void ACCharacterCase::InitAbilityAndAttribute()
{
	AbilitySystemComponent->ApplyInitialEffect();
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
	StatusGauge = Cast<UStatusGauge> (StatusWidgetComp->GetUserWidgetObject());
	if (!StatusGauge)
	{
		UE_LOG(LogTemp, Error, TEXT("$s can't spawn status gauge hud, status widget component has the wrong widget setup"), *GetName());
		return;
	}
}

UAbilitySystemComponent* ACCharacterCase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ACCharacterCase::HealthUpdated(const FOnAttributeChangeData& ChangeData)
{
	if(StatusGauge)
	StatusGauge->SetHealth(ChangeData.NewValue, AttributeSet->GetMaxHealth());
}

void ACCharacterCase::MaxHealthUpdated(const FOnAttributeChangeData& ChangeData)
{
	if(StatusGauge)
	StatusGauge->SetHealth(AttributeSet->GetHealth(), ChangeData.NewValue);
}
