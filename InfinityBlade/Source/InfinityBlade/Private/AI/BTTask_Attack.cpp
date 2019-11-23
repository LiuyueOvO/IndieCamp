// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTask_Attack.h"
#include "AI/MonsterController.h"
#include "AI/AICharacter.h"
#include "AI/AIAnimInstance.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

/** ��дִ������ڵ� */
EBTNodeResult::Type UBTTask_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	/** ��ȡController */
	AMonsterController* Controller = Cast<AMonsterController>(OwnerComp.GetAIOwner());

	/**һ����Χ���ҵ�Ȼ���ƶ�����*/
	UBlackboardComponent* Blackboard = Controller->BlackboardComponent;
	/**��ȡĿ��λ��*/
	FVector TargetLocation = Blackboard->GetValueAsVector(TEXT("TargetLocation"));
	/**��ȡ���߾���*/
	float Distance = FVector::Distance(Controller->GetPawn()->GetActorLocation(), TargetLocation);
	/**�ж��ƶ�*/
	if (Distance <= Dis)
	{
		Controller->MoveToLocation(TargetLocation);
		return EBTNodeResult::Succeeded;
	}

	///** ��ȡAI */
	//AAICharacter* Monster = Cast<AAICharacter>(Controller->GetPawn());
	///** ��ȡ����ʵ�� */
	//UAIAnimInstance* AIAnimInstance = Cast<UAIAnimInstance>(Monster->GetMesh()->GetAnimInstance());
	///** �жϵ�ǰ�Ƿ����ڲ��Ŷ�����̫�� */
	//if (!AIAnimInstance->bIsPlaying)
	//{
	//	/** ������� */
	//	Controller->SetFocus(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	//	/** ��ȡ����� */
	//	uint8 RandomNum = FMath::FloorToInt(FMath::RandRange(0.f, Monster->AttackMontages.Num()*1.f));
	//	/** ������Ŷ�����̫�� */
	//	AIAnimInstance->Montage_Play(Monster->AttackMontages[RandomNum], 1.f);
	//}

	return EBTNodeResult::Failed;
}
