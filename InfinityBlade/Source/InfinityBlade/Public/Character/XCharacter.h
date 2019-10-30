// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Weapon/Weapon.h"
#include "XCharacter.generated.h"

/**
 * Ӣ�۽�ɫ��
 */
UCLASS()
class INFINITYBLADE_API AXCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	/** �������� */
	UPROPERTY(EditAnywhere)
		UCameraComponent* CameraComponent;
	/** ������ */
	UPROPERTY(EditAnywhere, Category = "Weapon")
		TSubclassOf<AWeapon> XWeaponClass;
public:
	/** ���췽�� */
	AXCharacter();

protected:
	/** ��Ϸ��ʼ���õķ��� */
	virtual void BeginPlay() override;

};
