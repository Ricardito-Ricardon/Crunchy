// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayAbilities/CAbilitySystemComponent.h"

void UCAbilitySystemComponent::ApplyGameplayEffects_Implementation(TSubclassOf<UGameplayEffect> EffectToApply, int Level)
{
	FGameplayEffectSpecHandle specHandle = MakeOutgoingSpec(EffectToApply,Level,MakeEffectContext());
	ApplyGameplayEffectSpecToSelf(*specHandle.Data.Get());
}

bool UCAbilitySystemComponent::ApplyGameplayEffects_Validate(TSubclassOf<UGameplayEffect> EffectToApply, int Level)
{
	return false;
}

void UCAbilitySystemComponent::ApplyInitialEffect()
{
	for (const TSubclassOf<UGameplayEffect>& Effect : InitialEffects)
	{
		ApplyGameplayEffect(Effect, 1);
	}
}
