// Fill out your copyright notice in the Description page of Project Settings.


#include "ABPlayerController.h"

// ����Ʈ Ŭ�����ص� �ٷ� �Է� ��ȣ�� ���ӿ� ���޵ǵ��� �ϴ� �Լ� (158p)
void AABPlayerController::BeginPlay()
{
	Super::BeginPlay();

	FInputModeGameOnly InputMode;
	SetInputMode(InputMode);
}