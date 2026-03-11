#include "ShopItemEntry.h"
#include "Components/TextBlock.h"
#include "ShopItemData.h"

void UShopItemEntry::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	UShopItemData* ItemData = Cast<UShopItemData>(ListItemObject);
	if (ItemData)
	{
		if (ItemNameText)
		{
			ItemNameText->SetText(FText::FromString(ItemData->ItemName));
		}
		if (ItemPriceText)
		{
			ItemPriceText->SetText(FText::FromString(FString::Printf(TEXT("%d Gold"), ItemData->Price)));
		}
	}
}