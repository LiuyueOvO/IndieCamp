// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UI/LoadUserWidget.h"
#include "Runtime/MoviePlayer/Public/MoviePlayer.h"
#include "CustomGameInstance.generated.h"

/**
 * 游戏实例
 */
UCLASS()
class INFINITYBLADE_API UCustomGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	/** 存储数据集合 */
	TMap<FString, FString> ContextMap;
	/** 加载的UI */
	UPROPERTY()
		ULoadUserWidget* LoadWidget;

public:
	/** 初始化方法 */
	virtual void Init() override;
	/** 地图加载开始的方法 */
	UFUNCTION()
		void PreLoadMap(const FString& Map);
	/** 地图加载结束的方法 */
	UFUNCTION()
		void PostLoadMap(UWorld* World);
	/** 是否加载完成 */
	UFUNCTION(BlueprintCallable, Category = LoadFunction)
		bool GetLoadStatus();
};

