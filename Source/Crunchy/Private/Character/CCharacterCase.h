// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "CCharacterCase.generated.h"

class UCAbilitySystemComponent;
class UCAttributeSet;

UCLASS()
class ACCharacterCase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACCharacterCase();
	void SetupAbilitySystemComponent();
	void InitAbilityAndAttribute();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Gameplay ability
public:
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
private:
	UPROPERTY(VisibleAnywhere, Category = "Gameplay Ability")
	UCAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY()
	UCAttributeSet* AttributeSet;

};
