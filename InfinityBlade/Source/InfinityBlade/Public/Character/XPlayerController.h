// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Character/XCharacter.h"
#include "XPlayerController.generated.h"

/**
 * ����Ӣ�۵Ŀ�����
 */
UCLASS()
class INFINITYBLADE_API AXPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	/** Ӣ�۽�ɫ���� */
	UPROPERTY()
		AXCharacter * XCharacter;


public:
	/** ��Ϸ��ʼ���õķ��� */
	virtual void BeginPlay() override;
	/** ������ؼ� */
	virtual void SetupInputComponent() override;


public:
	/** ǰ���ƶ� */
	UFUNCTION()
		void MoveForward(float Speed);
	/** �����ƶ� */
	UFUNCTION()
		void MoveRight(float Speed);
};
