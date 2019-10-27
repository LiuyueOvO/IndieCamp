// Fill out your copyright notice in the Description page of Project Settings.


#include "MainGameMode.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "GameFramework/Character.h"
#include "Character/XPlayerController.h"

/** ���췽�� */
AMainGameMode::AMainGameMode()
{
	/** �ҵ���Դ���Character��ͼ�� */
	ConstructorHelpers::FClassFinder<ACharacter> CharacterFinder(TEXT("/Game/Character/BP_XCharacter"));
	DefaultPawnClass = CharacterFinder.Class;
	/** ����PlayerController */
	PlayerControllerClass = AXPlayerController::StaticClass();
};
