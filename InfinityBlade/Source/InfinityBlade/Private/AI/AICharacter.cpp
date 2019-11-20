// Fill out your copyright notice in the Description page of Project Settings.


#include "AICharacter.h"

/** ���췽�� */
AAICharacter::AAICharacter()
{
	/** ��ʼ��UI�ؼ� */
	WidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("WidgetComponent"));
	WidgetComponent->SetupAttachment(GetMesh());
}

/** ��Ϸ��ʼ���õķ��� */
void AAICharacter::BeginPlay()
{
	Super::BeginPlay();
	/** ��ʼ��Ѫ�� */
	HPBar = Cast<UProgressBar>(WidgetComponent->GetUserWidgetObject()->GetWidgetFromName(TEXT("AIHPBar")));
	/** ��ʼ����ǰѪ�� */
	CurrentHP = TotalHP;
	/** ��ʼ����ǰ��Ѫ��UI */
	HPBar->SetPercent(CurrentHP / TotalHP);
}


/** ��д�յ��˺��ķ��� */
float AAICharacter::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	/** ��ǰѪ������ */
	CurrentHP -= Damage;
	/** ����UI */
	HPBar->SetPercent(CurrentHP / TotalHP);

	return Damage;
}

