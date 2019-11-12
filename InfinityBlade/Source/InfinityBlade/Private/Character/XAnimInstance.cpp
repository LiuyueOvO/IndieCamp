// Fill out your copyright notice in the Description page of Project Settings.


#include "XAnimInstance.h"


/** ���������ƶ��ٶ� */
void UXAnimInstance::UpdateSpeed()
{
	if (TryGetPawnOwner() != nullptr)
	{
		Speed = TryGetPawnOwner()->GetVelocity().Size();
	}
}

/** ��ʼ������̫�� */
void UXAnimInstance::AnimNotify_PlayStart(UAnimNotify* Notify)
{
	bIsPlaying = true;
}

/** ����������̫�� */
void UXAnimInstance::AnimNotify_PlayEnd(UAnimNotify* Notify)
{
	bIsPlaying = false;
}

/** ��������״̬ */
void UXAnimInstance::AnimNotify_ResetSerialAttack(UAnimNotify* Notify)
{
	bIsEnableSecondAttack = false;
	bIsEnableThreeAttack = false;
	bIsEnableFourAttack = false;
	bIsEnableFiveAttack = false;
}

/** ����ڶ������� */
void UXAnimInstance::AnimNotify_SecondAttackInput(UAnimNotify* Notify)
{
	bIsEnableSecondAttack = true;
}

/** ������������� */
void UXAnimInstance::AnimNotify_ThreeAttackInput(UAnimNotify* Notify)
{
	bIsEnableThreeAttack = true;
}

/** ������Ĵ����� */
void UXAnimInstance::AnimNotify_FourAttackInput(UAnimNotify* Notify)
{
	bIsEnableFourAttack = true;
}

/** ������������ */
void UXAnimInstance::AnimNotify_FiveAttackInput(UAnimNotify* Notify)
{
	bIsEnableFiveAttack = true;
}
