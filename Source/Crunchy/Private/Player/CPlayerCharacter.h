// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/CCharacterCase.h"
#include "CPlayerCharacter.generated.h"

//Forward declaration. I am telling the compiler that this class exists.
class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
/**
 * 
 */
UCLASS()
class ACPlayerCharacter : public ACCharacterCase
{
	GENERATED_BODY()
public:
	//This is the constructor
	ACPlayerCharacter();

private:
	UPROPERTY(visibleAnywhere, Category="View")
	class USpringArmComponent* cameraBoom;

	UPROPERTY(visibleAnywhere, Category = "View")
	class UCameraComponent* viewCamera;

	virtual void PawnClientRestart();

	/**********************************/
	//Input
	/**********************************/
	UPROPERTY(editDefaultsOnly, Category = "Input")
	UInputMappingContext* inputMapping;
	UPROPERTY(editDefaultsOnly, Category = "Input")
	UInputAction* moveInputAction;
	UPROPERTY(editDefaultsOnly, Category = "Input")
	UInputAction* lookInputAction;

	UPROPERTY(editDefaultsOnly, Category = "Input")
	UInputAction* jumpInputAction;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void Move(const FInputActionValue& InputValue);

	UFUNCTION()
	void Look(const FInputActionValue& InputValue);

	FVector GetMoveFwdDir() const;
	FVector GetMoveRightDir()  const;
};
