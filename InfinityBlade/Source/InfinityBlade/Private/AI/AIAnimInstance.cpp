// Fill out your copyright notice in the Description page of Project Settings.


#include "AIAnimInstance.h"

/** ���������ƶ��ٶ� */
void UAIAnimInstance::UpdateSpeed()
{
	if (TryGetPawnOwner() != nullptr)
	{
		Speed = TryGetPawnOwner()->GetVelocity().Size();
	}
}