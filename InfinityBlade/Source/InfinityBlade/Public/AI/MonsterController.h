// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Weapon/Weapon.h"
#include "MonsterController.generated.h"

/**
 * AI������
 */
UCLASS()
class INFINITYBLADE_API AMonsterController : public AAIController
{
	GENERATED_BODY()

public:
	/** ��Ϊ���ؼ� */
	UPROPERTY()
		UBehaviorTreeComponent* BehaviorTreeComponent;
	/** �ڰ�ؼ� */
	UPROPERTY()
		UBlackboardComponent* BlackboardComponent;
	/** �������� */
	UPROPERTY()
		AWeapon* AIWeapon;

public:
	/** ���췽�� */
	AMonsterController();
	/** ��д���Ƶķ��� */
	virtual void OnPossess(APawn* InPawn) override;
};
