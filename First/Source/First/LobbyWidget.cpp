#include "LobbyWidget.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"

void ULobbyWidget::NativeConstruct()
{
	Super::NativeConstruct();

	UE_LOG(LogTemp, Log, TEXT("LobbyWidget NativeConstruct called!"));

	if (ShopButton)
	{
		UE_LOG(LogTemp, Log, TEXT("ShopButton found!"));
		ShopButton->OnClicked.AddDynamic(this, &ULobbyWidget::OnShopButtonClicked);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("ShopButton is NULL!"));
	}

	if (InventoryButton)
	{
		InventoryButton->OnClicked.AddDynamic(this, &ULobbyWidget::OnInventoryButtonClicked);
	}

	if (SettingsButton)
	{
		SettingsButton->OnClicked.AddDynamic(this, &ULobbyWidget::OnSettingsButtonClicked);
	}
}

void ULobbyWidget::OnShopButtonClicked()
{
	if (ContentSwitcher)
	{
		ContentSwitcher->SetActiveWidgetIndex(0);
	}
}

void ULobbyWidget::OnInventoryButtonClicked()
{
	if (ContentSwitcher)
	{
		ContentSwitcher->SetActiveWidgetIndex(1);
	}
}

void ULobbyWidget::OnSettingsButtonClicked()
{
	if (ContentSwitcher)
	{
		ContentSwitcher->SetActiveWidgetIndex(2);
	}
}