// Fill out your copyright notice in the Description page of Project Settings.


#include "ABPlayerController.h"

// 뷰포트 클릭안해도 바로 입력 신호가 게임에 전달되도록 하는 함수 (158p)
void AABPlayerController::BeginPlay()
{
	Super::BeginPlay();

	FInputModeGameOnly InputMode;
	SetInputMode(InputMode);
}