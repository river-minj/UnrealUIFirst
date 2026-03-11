// Fill out your copyright notice in the Description page of Project Settings.


#include "SettingsWidget.h"
#include "Components/Slider.h"
#include "Components/TextBlock.h"

void USettingsWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (BGMSlider)
	{
		BGMSlider->SetValue(0.5f);
		BGMSlider->OnValueChanged.AddDynamic(this, &USettingsWidget::OnBGMVolumeChanged);
		OnBGMVolumeChanged(0.5f);
	}

	if (SFXSlider)
	{
		SFXSlider->SetValue(0.5f);
		SFXSlider->OnValueChanged.AddDynamic(this, &USettingsWidget::OnSFXVolumeChanged);
		OnSFXVolumeChanged(0.5f);
	}
}

void USettingsWidget::OnBGMVolumeChanged(float Value)
{
	if (BGMValueText)
	{
		int32 DisplayValue = FMath::RoundToInt(Value * 100.f);
		BGMValueText->SetText(FText::FromString(FString::Printf(TEXT("%d"), DisplayValue)));
	}
	UE_LOG(LogTemp, Log, TEXT("BGM Volume: %f"), Value);
}

void USettingsWidget::OnSFXVolumeChanged(float Value)
{
	if (SFXValueText)
	{
		int32 DisplayValue = FMath::RoundToInt(Value * 100.f);
		SFXValueText->SetText(FText::FromString(FString::Printf(TEXT("%d"), DisplayValue)));
	}
	UE_LOG(LogTemp, Log, TEXT("SFX Volume: %f"), Value);
}
