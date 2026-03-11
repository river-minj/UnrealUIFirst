// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SettingsWidget.generated.h"

class USlider;
class UTextBlock;

UCLASS()
class FIRST_API USettingsWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativeConstruct() override;

	UFUNCTION()
	void OnBGMVolumeChanged(float Value);

	UFUNCTION()
	void OnSFXVolumeChanged(float Value);

	UPROPERTY(meta = (BindWidget))
	USlider* BGMSlider;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* BGMValueText;

	UPROPERTY(meta = (BindWidget))
	USlider* SFXSlider;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* SFXValueText;

};
