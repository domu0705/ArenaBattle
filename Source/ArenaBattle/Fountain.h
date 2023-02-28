// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ArenaBattle.h"
#include "GameFramework/RotatingMovementComponent.h"// 독립적인 회전 컴포넌트 
#include "GameFramework/Actor.h"
#include "Fountain.generated.h"

UCLASS()
class ARENABATTLE_API AFountain : public AActor
{
	GENERATED_BODY()
	

public:	
	// Sets default values for this actor's properties
	AFountain();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void PostInitializeComponents() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(VisibleAnywhere)//72p
	UStaticMeshComponent* Body;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Water;

	UPROPERTY(VisibleAnywhere)
		UPointLightComponent* Light;
	UPROPERTY(VisibleAnywhere)
		UParticleSystemComponent* Splash;


	//독립적인 회전 컴포넌트 사용을 위함
	UPROPERTY(VisibleAnywhere)
		URotatingMovementComponent* Movement;
private:
	UPROPERTY(EditAnywhere, Category = Stat, Meta = (AllowPrivateAccess = true))//Meta = (AllowPrivateAccess = true) 은 private에서도 편집 가능함과 동시에 변수 데이터를 은닉하게 하여 캡슐화 가능.
		float RotateSpeed;
};
