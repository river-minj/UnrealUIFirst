// Fill out your copyright notice in the Description page of Project Settings.


#include "SettingsWidget.h"
#include "Components/Slider.h"
#include "Components/TextBlock.h"
#include "Components/CheckBox.h"
#include "Components/ComboBoxString.h"

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

	if (FullscreenCheckBox)
	{
		FullscreenCheckBox->OnCheckStateChanged.AddDynamic(this, &USettingsWidget::OnFullscreenChange);

	}

	if (LanguageComboBox)
	{
		LanguageComboBox->AddOption(TEXT("한국어"));
		LanguageComboBox->AddOption(TEXT("English"));
		LanguageComboBox->SetSelectedIndex(0);
		LanguageComboBox->OnSelectionChanged.AddDynamic(this, &USettingsWidget::OnLanguageChanged);

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

void USettingsWidget::OnFullscreenChange(bool bIsChekcked)
{
	UE_LOG(LogTemp, Log, TEXT("Fullscreen: %s"), bIsChekcked ? TEXT("ON") : TEXT("OFF"));
}

void USettingsWidget::OnLanguageChanged(FString SelectedItem, ESelectInfo::Type SelectedType)
{
	UE_LOG(LogTemp, Log, TEXT("Language: %s"), *SelectedItem)
}
