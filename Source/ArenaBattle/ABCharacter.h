// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ArenaBattle.h"
#include "GameFramework/Character.h"
#include "ABCharacter.generated.h"

UCLASS()
class ARENABATTLE_API AABCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AABCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void SetControlMode(int32 ControlMode);

	FVector DirectionToMove = FVector::ZeroVector;
	float ArmLengthTo = 0.0f;
	FRotator ArmRotationTo = FRotator::ZeroRotator;
	float ArmLengthSpeed = 0.0f;
	float ArmRotationSpeed = 0.0f;

public:	
	UPROPERTY(VisibleAnywhere, Category = Camera)//category는 UE에서 보이는 항목의 이름을 설정하는 것임.
		USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, Category = Camera)//category는 UE에서 보이는 항목의 이름을 설정하는 것임.
		UCameraComponent* Camera;
	UPROPERTY(VisibleAnywhere, Category = Weapon)//category는 UE에서 보이는 항목의 이름을 설정하는 것임.
		USkeletalMeshComponent* Weapon;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void PostInitializeComponents() override;
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;
	bool CanSetWeapon();
	void SetWeapon(class AABWeapon* NewWeapon);
private:
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
		bool IsAttacking;
	UPROPERTY()
		class UABAnimInstance* ABAnim;
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
		float AttackRange;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
		float AttackRadius;
	UPROPERTY(VisibleInstanceOnly, Category = Weapon)
		class AABWeapon* CurrentWeapon;

	void UpDown(float NewAxisValue);
	void LeftRight(float NewAxisValue);
	void LookUp(float NewAxisValue);
	void Turn(float NewAxisValue);
	void Attack();
	void AttackCheck();
	UFUNCTION()
		void OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted);
};
