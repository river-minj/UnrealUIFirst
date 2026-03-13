// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h" //언리얼 기본 기능
#include "Blueprint/UserWidget.h" //위젯 부모 클래스
#include "TitleScreenWidget.generated.h" //언리얼 매크로 지원 (항상 해더 파일의 마지막에 위치해야한다.)

/**
 * 
 */

class UButton;
class UTextBlock;

UCLASS()
class FIRST_API UTitleScreenWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

private:
	UPROPERTY(meta = (BindWidget))
	UButton* StartButton;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TitleText;

	UPROPERTY(meta = (BindWidgetAnim), Transient)
	UWidgetAnimation* FadeOutAnim;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<UUserWidget> LobbyWidghetClass;

	UPROPERTY(meta = (BindWidgetAnim), Transient)
	UWidgetAnimation* FadeInAnim;

	UFUNCTION()
	void OnStartButtonClicked();

	UFUNCTION()
	void OnFadeOutFinished();
};
