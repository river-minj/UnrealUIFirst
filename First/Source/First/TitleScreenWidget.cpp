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

	if (FadeOutAnim)
	{
		FWidgetAnimationDynamicEvent EndDelegate;
		EndDelegate.BindDynamic(this, &UTitleScreenWidget::OnFadeOutFinished);
		BindToAnimationFinished(FadeOutAnim, EndDelegate);
	}

	if (FadeInAnim)
	{
		PlayAnimation(FadeInAnim);
	}
}

void UTitleScreenWidget::OnStartButtonClicked()
{
	if (FadeOutAnim)
	{
		PlayAnimation(FadeOutAnim);
	}

	UE_LOG(LogTemp, Log, TEXT("Start Button Clicked"))
}

void UTitleScreenWidget::OnFadeOutFinished()
{
	if (LobbyWidghetClass)
	{
		UUserWidget* LobbyWidget = CreateWidget<UUserWidget>(GetWorld(), LobbyWidghetClass);
		if (LobbyWidget)
		{
			LobbyWidget->AddToViewport();
			RemoveFromParent();
		}
	}
}