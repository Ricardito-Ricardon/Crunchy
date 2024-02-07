// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "StatusGauge.generated.h"

/**
 * 
 */
UCLASS()
class UStatusGauge : public UUserWidget
{
	GENERATED_BODY()
public:
	void SetHealth(float NewHealth, float MaxHealth);
	void SetMana(float NewMana, float MaxMana);
	
private:
	UPROPERTY(meta=(BindWidget))
	class UValueGauge* HealthBar;
	UPROPERTY(meta=(BindWidget))
	class UValueGauge* ManaBar;
};
