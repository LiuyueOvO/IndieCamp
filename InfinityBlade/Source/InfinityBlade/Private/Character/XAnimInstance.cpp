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
