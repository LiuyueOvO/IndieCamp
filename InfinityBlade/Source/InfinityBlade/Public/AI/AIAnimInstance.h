// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "AIAnimInstance.generated.h"

/**
 * AI����ʵ��
 */
UCLASS()
class INFINITYBLADE_API UAIAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	/** ������ƶ��ٶ� */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float Speed;

public:
	/** ���������ƶ��ٶ� */
	UFUNCTION(BlueprintCallable)
		void UpdateSpeed();
};
