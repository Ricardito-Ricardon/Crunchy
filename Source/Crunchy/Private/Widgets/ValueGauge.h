// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ValueGauge.generated.h"

/**
 * 
 */
UCLASS()
class UValueGauge : public UUserWidget
{
	GENERATED_BODY()

public:
	//This is used to update the settings in the UI designer
	virtual void NativePreConstruct() override;

	void SetValue(float NewVal, float NewMaxValue);
	
private:
	UPROPERTY(EditAnywhere, Category="Visual")
	FLinearColor FillColor;


	UPROPERTY(VisibleDefaultsOnly, meta=(BindWidget))
	class UProgressBar* ProgressBar;

	UPROPERTY(VisibleDefaultsOnly, meta=(BindWidget))
	class UTextBlock* DisplayText;
};
