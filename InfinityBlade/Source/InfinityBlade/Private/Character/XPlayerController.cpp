// Fill out your copyright notice in the Description page of Project Settings.


#include "XPlayerController.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/Kismet/KismetMathLibrary.h"

/** ��Ϸ��ʼ���õķ��� */
void AXPlayerController::BeginPlay()
{
	/** ������ʾ��� */
	bShowMouseCursor = true;
	/** ��ʼ��Ӣ�۽�ɫ����*/
	XCharacter = Cast<AXCharacter>(GetPawn());

	/** ��ʼ��Ӣ�۽�ɫ����*/
	XAnimInstance = Cast<UXAnimInstance>(XCharacter->GetMesh()->GetAnimInstance());

	/** ��ʼ��������UI */
	MainWidget = CreateWidget<UMainUserWidget>(GetGameInstance(), LoadClass<UMainUserWidget>(nullptr, TEXT("WidgetBlueprint'/Game/UI/BP_MainUserWidget.BP_MainUserWidget_C'")));
	/** ��ӵ��ӿ� */
	MainWidget->AddToViewport();

	/** �ж��������Ƿ���Ч */
	if (XCharacter->XWeaponClass)
	{
		/** ����һ���������� */
		XWeapon = GetWorld()->SpawnActor<AWeapon>(XCharacter->XWeaponClass);
		/** �󶨹��� */
		FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, EAttachmentRule::KeepRelative, EAttachmentRule::KeepRelative, true);
		/** ������ */
		XWeapon->AttachToComponent(XCharacter->GetMesh(), AttachmentRules, TEXT("hand_rSocket"));
		/** �������ص��¼� */
		//pon->CapsuleComponent->OnComponentBeginOverlap.AddDynamic(this, &AXPlayerController::WeaponOverlapDamage);
	}


	/** ��ʼ����ť����¼� */
	InitWidgetEvent();
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


/** �ؼ���ť�¼���ʼ������ */
void AXPlayerController::InitWidgetEvent()
{
	/** ������ť����¼��� */
	if (MainWidget->Button_Attack)
	{
		MainWidget->Button_Attack->OnClicked.AddDynamic(this, &AXPlayerController::AttackBtnOnClickedEvent);
	}
}

/** ������ť����¼� */
void AXPlayerController::AttackBtnOnClickedEvent()
{
	/** �жϵ�ǰ��̫���Ƿ����ڲ���,������ڲ�������ֹ */
	if (XAnimInstance->bIsPlaying)
	{
		return;
	}
	/** �������������̫�� */
	UAnimMontage* SerialAttakMontage = XCharacter->SerialAttackMontage;
	/** ��õ�ǰ���ŵĽ� */
	FName CurrentSection = XAnimInstance->Montage_GetCurrentSection(SerialAttakMontage);
	/** �ж� */
	if (CurrentSection.IsNone())
	{
		/** Ĭ�ϲ��ŵ�һ���� */
		XAnimInstance->Montage_Play(SerialAttakMontage);
	}
	else if (CurrentSection.IsEqual(FName("FirstSection")) && XAnimInstance->bIsEnableSecondAttack)
	{
		/** ���ŵڶ����� */
		XAnimInstance->Montage_JumpToSection(FName("SecondSection"), SerialAttakMontage);
	}
	else if (CurrentSection.IsEqual(FName("SecondSection")) && XAnimInstance->bIsEnableThreeAttack)
	{
		/** ���ŵ������� */
		XAnimInstance->Montage_JumpToSection(FName("ThreeSection"), SerialAttakMontage);
	}
	else if (CurrentSection.IsEqual(FName("ThreeSection")) && XAnimInstance->bIsEnableFourAttack)
	{
		/** ���ŵ��ĸ��� */
		XAnimInstance->Montage_JumpToSection(FName("FourSection"), SerialAttakMontage);
	}
	else if (CurrentSection.IsEqual(FName("FourSection")) && XAnimInstance->bIsEnableFiveAttack)
	{
		/** ���ŵ������ */
		XAnimInstance->Montage_JumpToSection(FName("FiveSection"), SerialAttakMontage);
	}
}