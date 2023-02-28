// Fill out your copyright notice in the Description page of Project Settings.
// ���� ������� �ʴ� class. (���ABCharacter ���)
#pragma once

#include "ArenaBattle.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/FloatingPawnMovement.h"//�÷��̾� �Է¿� ���� ĳ���Ͱ� �����̵��� �������ִ� ������Ʈ
#include "ABPawn.generated.h"

UCLASS()
class ARENABATTLE_API AABPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AABPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//148p �÷��̾� �浹, �޽�(+anim), �̵�, ī�޶� ����, ī�޶� ����
	UPROPERTY(VisibleAnywhere, Category = Collision)
		UCapsuleComponent* Capsule;

	UPROPERTY(VisibleAnywhere, Category = Visual)
		USkeletalMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, Category = Movement)
		UFloatingPawnMovement* Movement;

	UPROPERTY(VisibleAnywhere, Category = Camera)
		USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, Category = Camera)
		UCameraComponent* Camera;

private:
	void UpDown(float NewAxisValue);
	void LeftRight(float NewAxisValue);
};