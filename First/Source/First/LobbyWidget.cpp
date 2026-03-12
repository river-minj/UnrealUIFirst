#include "LobbyWidget.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "Components/ListView.h"
#include "ShopItemData.h"
#include "InventoryItemData.h"
#include "Components/TileView.h"

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

	if (BackButton)
	{
		BackButton->OnClicked.AddDynamic(this, &ULobbyWidget::OnBackButtonClicked);
	}

	PopulateShopItems();
	PopulateInventoryItems();
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

void ULobbyWidget::OnBackButtonClicked()
{
	UUserWidget* TitleWidget = CreateWidget<UUserWidget>(GetWorld(), TitleWidgetClass);
	if (TitleWidget)
	{
		TitleWidget->AddToViewport();
		RemoveFromParent();
	}
}


void ULobbyWidget::PopulateShopItems()
{
	if (!ShopListView) return;

	UShopItemData* Sword = NewObject<UShopItemData>();
	Sword->Init(TEXT("장검"), 1000);
	ShopListView->AddItem(Sword);

	UShopItemData* Dagger = NewObject<UShopItemData>();
	Dagger->Init(TEXT("단검"), 500);
	ShopListView->AddItem(Dagger);

	UShopItemData* Shield = NewObject<UShopItemData>();
	Shield->Init(TEXT("방패"), 800);
	ShopListView->AddItem(Shield);

	UShopItemData* Potion = NewObject<UShopItemData>();
	Potion->Init(TEXT("물약"), 100);
	ShopListView->AddItem(Potion);
}

void ULobbyWidget::PopulateInventoryItems()
{

	if (!InventoryTileView) return;

	UInventoryItemData* Sword = NewObject<UInventoryItemData>();
	Sword->Init(TEXT("장검"), 1);
	InventoryTileView->AddItem(Sword);

	UInventoryItemData* Dagger = NewObject<UInventoryItemData>();
	Dagger->Init(TEXT("단검"), 3);
	InventoryTileView->AddItem(Dagger);

	UInventoryItemData* Shield = NewObject<UInventoryItemData>();
	Shield->Init(TEXT("방패"), 1);
	InventoryTileView->AddItem(Shield);

	UInventoryItemData* Potion = NewObject<UInventoryItemData>();
	Potion->Init(TEXT("물약"), 10);
	InventoryTileView->AddItem(Potion);

}
