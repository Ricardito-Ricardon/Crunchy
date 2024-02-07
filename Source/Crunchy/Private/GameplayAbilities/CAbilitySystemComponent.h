// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "CAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class UCAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(Server, Reliable, WithValidation) //this will signal the server to call this function. Reliable means it will eventually called. Unrealiable means it could be dropped.
	void ApplyGameplayEffect(TSubclassOf<UGameplayEffect> EffectToApply, int Level = 1);
	void ApplyInitialEffect();

private:
	UPROPERTY(EditDefaultsOnly, Category = "Init")
	TArray<TSubclassOf<UGameplayEffect>> InitialEffects;

};
