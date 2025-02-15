// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "Components/CircularThrobber.h"
#include "UI/MessageUserWidget.h"
#include "Runtime/Online/HTTP/Public/HttpModule.h"
#include "Runtime/Online/HTTP/Public/Interfaces/IHttpRequest.h"
#include "Runtime/Online/HTTP/Public/Interfaces/IHttpResponse.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "CustomGameInstance.h"
#include "LoginUserWidget.generated.h"

/**
 * 登录界面UI
 */
UCLASS()
class INFINITYBLADE_API ULoginUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	/** 返回按钮 */
	UPROPERTY()
		UButton* BackBtn;
	/** 昵称输入框 */
	UPROPERTY()
		UEditableTextBox* NicknameInput;
	/** 密码输入框 */
	UPROPERTY()
		UEditableTextBox* PasswordInput;
	/** 登录按钮 */
	UPROPERTY()
		UButton* LoginBtn;

	/** 进度条 */
	UPROPERTY()
		UCircularThrobber* CircularThrobber;
	/** 信息提示框 */
	UPROPERTY()
		UMessageUserWidget* MessageUserWidget;

public:
	/** 控件创建完成的初始化方法 */
	virtual bool Initialize() override;
	/** 登录按钮点击事件 */
	UFUNCTION()
		void LoginBtnOnClickedEvent();
	/** 用户登录的方法 */
	void AccountLoginFromServer(FString Nickname, FString Password);
	/** 请求的响应方法 */
	void RequestComplete(FHttpRequestPtr RequestPtr, FHttpResponsePtr ResponsePtr, bool bIsSuccess);
};
