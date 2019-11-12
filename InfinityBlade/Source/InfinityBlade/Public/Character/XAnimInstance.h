// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "XAnimInstance.generated.h"

/**
 * Ӣ�۽�ɫ�Ķ���ʵ��
 */
UCLASS()
class INFINITYBLADE_API UXAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
		/** ������ƶ��ٶ� */
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float Speed;

		/** �Ƿ��ڹ���״̬ */
		bool bIsAttacking;
		/** �Ƿ��ڲ���״̬ */
		bool bIsPlaying;
		/** �Ƿ����ڶ������� */
		bool bIsEnableSecondAttack;
		/** �Ƿ������������� */
		bool bIsEnableThreeAttack;
		/** �Ƿ������Ĵ����� */
		bool bIsEnableFourAttack;
		/** �Ƿ������������ */
		bool bIsEnableFiveAttack;

public:
	/** ���������ƶ��ٶ� */
	UFUNCTION(BlueprintCallable)
		void UpdateSpeed();

public:
	/** ��ʼ������̫�� */
	UFUNCTION()
		void AnimNotify_PlayStart(UAnimNotify* Notify);
	/** ����������̫�� */
	UFUNCTION()
		void AnimNotify_PlayEnd(UAnimNotify* Notify);

	/** ��������״̬ */
	UFUNCTION()
		void AnimNotify_ResetSerialAttack(UAnimNotify* Notify);
	/** ����ڶ������� */
	UFUNCTION()
		void AnimNotify_SecondAttackInput(UAnimNotify* Notify);
	/** ������������� */
	UFUNCTION()
		void AnimNotify_ThreeAttackInput(UAnimNotify* Notify);
	/** ������Ĵ����� */
	UFUNCTION()
		void AnimNotify_FourAttackInput(UAnimNotify* Notify);
	/** ������������ */
	UFUNCTION()
		void AnimNotify_FiveAttackInput(UAnimNotify* Notify);
};
