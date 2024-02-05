// Fill out your copyright notice in the Description page of Project Settings.


#include "Framework/CAnimInstance.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

void UCAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	OwnerCharacter = Cast<ACharacter>(TryGetPawnOwner());
	if (OwnerCharacter)
	{
		OwnerMovementComp = OwnerCharacter->GetCharacterMovement();
		PrevRot = OwnerCharacter->GetActorRotation();
	}
}

void UCAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);
	if (OwnerCharacter)
	{
		Speed = OwnerCharacter->GetVelocity().Length();
		bIsJumping = OwnerMovementComp->IsFalling();

		FRotator characterRot = OwnerCharacter->GetActorRotation();
		FRotator lookRot = OwnerCharacter->GetViewRotation();

		lookOffset = (lookRot - characterRot).GetNormalized();

		FRotator RotDelta = (characterRot - PrevRot).GetNormalized();
		PrevRot = characterRot;

		YawSpeed = FMath::FInterpTo(YawSpeed, RotDelta.Yaw/DeltaSeconds, DeltaSeconds, 10.f);
	}
}
