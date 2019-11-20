// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Character/XCharacter.h"
#include "UI/MainUserWidget.h"
#include "Character/XAnimInstance.h"
#include "Character/XPlayerState.h"
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
	/** ���״̬ */
	UPROPERTY()
		AXPlayerState* XPlayerState;
	/** Ӣ�۽�ɫ����ʵ�� */
	UPROPERTY()
		UXAnimInstance* XAnimInstance;
	/** AI���� */
	UPROPERTY()
		TArray<AActor*> AiArray;

public:
	/** ������UI */
	UPROPERTY()
		UMainUserWidget* MainWidget;
public:
	/** �������� */
	UPROPERTY()
		AWeapon* XWeapon;

public:
	/** ��Ϸ��ʼ���õķ��� */
	virtual void BeginPlay() override;
	/** ������ؼ� */
	virtual void SetupInputComponent() override;

public:
	/** ����֮ʯ��ʱ�� */
	FTimerHandle IceStoneTimer;
	/** �ܹ���ȴʱ�� */
	float IceStoneTotalCD;
	/** ��ǰ��ȴʱ�� */
	float IceStoneCurrentCD;

public:
	/** ǰ���ƶ� */
	UFUNCTION()
		void MoveForward(float Speed);
	/** �����ƶ� */
	UFUNCTION()
		void MoveRight(float Speed);
public:
	/** ��ʼ�����״̬ */
	void InitState();

	/** ��ʼ��UI */
	void UpdateUI();/** �����˺����� */
	UFUNCTION()
		void WeaponOverlapDamage(UPrimitiveComponent* OverlapedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 BodyIndex, bool FromSweep, const FHitResult& HitResult);
	/** �������˷��� */
	void LockAI();

	/** �ؼ���ť�¼���ʼ������ */
	void InitWidgetEvent();
	/** ������ť����¼� */
	UFUNCTION()
		void AttackBtnOnClickedEvent();


	/** ����֮ʯ���ܵ���¼� */
	UFUNCTION()
		void IceStoneBtnOnClickedEvent();
	/** ����֮ʯ��ʱ���ص����� */
	void IceStoneCallback();

	/** �ָ�֮�����ܵ���¼� */
	UFUNCTION()
		void CureBtnOnClickedEvent();

	/** ����֮�⼼�ܵ���¼� */
	UFUNCTION()
		void ThunderBtnOnClickedEvent();
	/** �޾�֮�м��ܵ���¼� */
	UFUNCTION()
		void XBladeBtnOnClickedEvent();
};
