// Fill out your copyright notice in the Description page of Project Settings.


#include "XPlayerController.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/Kismet/KismetMathLibrary.h"

/** ��Ϸ��ʼ���õķ��� */
void AXPlayerController::BeginPlay()
{

	XCharacter = Cast<AXCharacter>(GetPawn());
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
}