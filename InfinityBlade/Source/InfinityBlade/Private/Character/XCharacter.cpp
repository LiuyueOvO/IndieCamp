// Fill out your copyright notice in the Description page of Project Settings.


#include "XCharacter.h"

/** ���췽�� */
AXCharacter::AXCharacter()
{
	/** ��ʼ�������� */
	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CamerComponent");
}

/** ��Ϸ��ʼ���õķ��� */
void AXCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}


