// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/ValueGauge.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"

void UValueGauge::NativePreConstruct()
{
	Super::NativePreConstruct();
	ProgressBar->SetFillColorAndOpacity(FillColor);
}

void UValueGauge::SetValue(float NewVal, float NewMaxValue)
{
	if (NewMaxValue == 0)
	{
		UE_LOG(LogTemp, Error, TEXT("Value Gauge: %s is getting a max value of 0, cannot calculate percent for progess bar"), *GetName());
		return;
	}

	float Percent = NewVal / NewMaxValue;
	ProgressBar->SetPercent(Percent);

	FText Text = FText::Format(FText::FromString("{0}/{1}"), FText::AsNumber((int)NewVal), FText::AsNumber((int)NewMaxValue));
	DisplayText->SetText(Text);
}
