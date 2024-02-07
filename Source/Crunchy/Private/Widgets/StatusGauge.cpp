// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/StatusGauge.h"
#include "Widgets/ValueGauge.h"
#include "StatusGauge.h"

void UStatusGauge::SetHealth(float NewHealth, float MaxHealth)
{
	HealthBar->SetValue(NewHealth, MaxHealth);
}

void UStatusGauge::SetMana(float NewMana, float MaxMana)
{
	ManaBar->SetValue(NewMana, MaxMana);
}
