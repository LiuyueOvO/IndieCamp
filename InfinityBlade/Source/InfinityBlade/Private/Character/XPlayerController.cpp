// Fill out your copyright notice in the Description page of Project Settings.


#include "XPlayerController.h"

/** ��Ϸ��ʼ���õķ��� */
void AXPlayerController::BeginPlay()
{

	XCharacter = Cast<AXCharacter>(GetPawn());
}

/** ������ؼ� */
void AXPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	/** ������ */
	InputComponent->BindAxis("MoveForward", this, &AXPlayerController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AXPlayerController::MoveRight);
}


/** ǰ���ƶ� */
void AXPlayerController::MoveForward(float Speed)
{
	/** ��ȡ�������ĽǶ� */
	FRotator Rotation = GetControlRotation();
	/** ����ƫ���� */
	FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	/** ��ȡ�ƶ��ķ��� */
	FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	/** �ڸ÷������λ�� */
	XCharacter->AddMovementInput(Direction, Speed);
}

/** �����ƶ� */
void AXPlayerController::MoveRight(float Speed)
{
	/** ��ȡ�������ĽǶ� */
	FRotator Rotation = GetControlRotation();
	/** ����ƫ���� */
	FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	/** ��ȡ�ƶ��ķ��� */
	FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	/** �ڸ÷������λ�� */
	XCharacter->AddMovementInput(Direction, Speed);
}
