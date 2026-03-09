// Fill out your copyright notice in the Description page of Project Settings.


#include "TitleScreenWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"

void UTitleScreenWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (StartButton)
	{
		StartButton->OnClicked.AddDynamic(this, &UTitleScreenWidget::OnStartButtonClicked);
	}
}

void UTitleScreenWidget::OnStartButtonClicked()
{
	UE_LOG(LogTemp, Log, TEXT("Start Button Clicked"))
}