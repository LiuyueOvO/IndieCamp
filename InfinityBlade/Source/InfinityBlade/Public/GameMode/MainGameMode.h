// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "MainGameMode.generated.h"

/**
 * 主关卡游戏模式
 */
UCLASS()
class INFINITYBLADE_API AMainGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	/** 构造方法 */
	AMainGameMode();
};
