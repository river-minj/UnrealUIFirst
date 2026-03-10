#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LobbyWidget.generated.h"

class UButton;
class UWidgetSwitcher;

UCLASS()
class FIRST_API ULobbyWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

protected:
	UPROPERTY(meta = (BindWidget))
	UButton* ShopButton;

	UPROPERTY(meta = (BindWidget))
	UButton* InventoryButton;

	UPROPERTY(meta = (BindWidget))
	UButton* SettingsButton;

	UPROPERTY(meta = (BindWidget))
	UWidgetSwitcher* ContentSwitcher;

	UFUNCTION()
	void OnShopButtonClicked();

	UFUNCTION()
	void OnInventoryButtonClicked();

	UFUNCTION()
	void OnSettingsButtonClicked();
};