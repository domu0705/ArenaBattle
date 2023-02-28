// Fill out your copyright notice in the Description page of Project Settings.


#include "ABGameModeBase.h"
#include "ABCharacter.h"
#include "ABPlayerController.h"

AABGameModeBase::AABGameModeBase()
{
	//DefaultPawnClass = AABPawn::StaticClass();//���� ��忡 ���� �����ϴ� �ڵ� (133P)
	DefaultPawnClass = AABCharacter::StaticClass();//
	PlayerControllerClass = AABPlayerController::StaticClass();//135p
}
