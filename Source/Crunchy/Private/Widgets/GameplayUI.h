// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameplayEffectTypes.h"
#include "GameplayUI.generated.h"

/**
 * 
 */
UCLASS()
class UGameplayUI : public UUserWidget
{
	GENERATED_BODY()

public:
	//This is the begin play or start
	virtual void NativeConstruct() override;
	
private:
	UPROPERTY(meta=(BindWidget))
	class UStatusGauge* StatusGauge;

	void HealthUpdated(const FOnAttributeChangeData& ChangeData);
	void MaxHealthUpdated(const FOnAttributeChangeData& ChangeData);

	float GetAttributeValue(const FGameplayAttribute Attribute) const;

	UPROPERTY()
	const class UAbilitySystemComponent* OwmnerAbilitySystemComponent;
};
