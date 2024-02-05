// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayAbilities/CAbilitySystemComponent.h"

void UCAbilitySystemComponent::ApplyGameplayEffects(const TSubclassOf<UGameplayEffect>& EffectToApply, int Level)
{
	FGameplayEffectSpecHandle specHandle = MakeOutgoingSpec(EffectToApply,Level,MakeEffectContext());
	ApplyGameplayEffectSpecToSelf(*specHandle.Data.Get());
}

void UCAbilitySystemComponent::ApplyInitialEffects()
{
	for (const TSubclassOf<UGameplayEffect>& Effect : InitialEffects)
	{
		ApplyGameplayEffects(Effect, 1);
	}
}
