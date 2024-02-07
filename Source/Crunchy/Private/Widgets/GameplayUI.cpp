// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/GameplayUI.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"

#include "GameplayAbilities/CAttributeSet.h"
#include "Widgets/StatusGauge.h"

void UGameplayUI::NativeConstruct()
{
	Super::NativeConstruct();

	UAbilitySystemComponent* OwnerASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetOwningPlayerPawn());
	if (OwnerASC)
	{
		OwnerASC->GetGameplayAttributeValueChangeDelegate(UCAttributeSet:GetHealthAttribute()).AddUObject(this, &UGameplayUI::HealthUpdated);
		OwnerASC->GetGameplayAttributeValueChangeDelegate(UCAttributeSet:GetMaxHealthAttribute()).AddUObject(this, &UGameplayUI::MaxHealthUpdated);
	}

	OwmnerAbilitySystemComponent = OwnerASC;
}

void UGameplayUI::HealthUpdated(const FOnAttributeChangeData& ChangeData)
{
	StatusGauge->SetHealth(ChanegData.NewValue, GetAttributeValue(UCAttributeSet::GetMaxHealthAttribute());
}

void UGameplayUI::MaxHealthUpdated(const FOnAttributeChangeData& ChangeData)
{
	StatusGauge->SetHealth(GetAttributeValue(UCAttributeSet::GetHealthAttribute()), ChangeData.NewValue);
}

float UGameplayUI::GetAttributeValue(const FGameplayAttribute Attribute) const
{
	if (OwmnerAbilitySystemComponent)
	{
		bool FOund = false;
		OwmnerAbilitySystemComponent->GetGameplayAttributeValue(Attribute, Found);
		if (Found)
		{
			return value;
		}
	}
	UE_LOG(LogTemp, Warning, TEXT("%s Can't find attribute: %s"). *GetName(), *Attribute.AttributeName);

	return -1;
}
