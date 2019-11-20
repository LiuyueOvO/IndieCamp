// Fill out your copyright notice in the Description page of Project Settings.


#include "MonsterController.h"
#include "AI/AICharacter.h"


/** ���췽�� */
AMonsterController::AMonsterController()
{
	/** ��ʼ����Ϊ���ؼ� */
	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComponent"));
	/** ��ʼ���ڰ�ؼ� */
	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComponent"));
}

/** ��д���Ƶķ��� */
void AMonsterController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	/** ��ʼ��AI�� */
	AAICharacter* Monster = Cast<AAICharacter>(InPawn);
	///** ��ʼ������ʵ�� */
	//AnimInstance = Cast<UAIAnimInstance>(Monster->GetMesh()->GetAnimInstance());

	///** �ж��������Ƿ���Ч */
	//if (Monster->AIWeaponClass)
	//{
	//	/** ����һ���������� */
	//	AIWeapon = GetWorld()->SpawnActor<AWeapon>(Monster->AIWeaponClass);
	//	/** �󶨹��� */
	//	FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, EAttachmentRule::KeepRelative, EAttachmentRule::KeepRelative, true);
	//	/** ������ */
	//	AIWeapon->AttachToComponent(Monster->GetMesh(), AttachmentRules, TEXT("hand_rSocket"));
	//	/** �������ص��¼� */
	//	AIWeapon->CapsuleComponent->OnComponentBeginOverlap.AddDynamic(this, &AMonsterController::WeaponOverlapDamage);
	//}

	/** �ж���Ϊ���ؼ� */
	if (Monster->BehaviorTree)
	{
		/** ��ʼ���ڰ� */
		BlackboardComponent->InitializeBlackboard(*((Monster->BehaviorTree->BlackboardAsset)));
		/** ������Ϊ�� */
		BehaviorTreeComponent->StartTree(*(Monster->BehaviorTree));
	}
}