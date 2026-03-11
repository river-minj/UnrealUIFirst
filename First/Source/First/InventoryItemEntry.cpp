// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryItemEntry.h"
#include "Components/TextBlock.h"
#include "InventoryItemData.h"

void UInventoryItemEntry::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	UInventoryItemData* ItemData = Cast<UInventoryItemData>(ListItemObject);
	if (ItemData)
	{
		if (ItemNameText)
		{
			ItemNameText->SetText(FText::FromString(ItemData->ItemName));
		}
		if (ItemQuantityText)
		{
			ItemQuantityText->SetText(FText::FromString(FString::Printf(TEXT("x%d"), ItemData->Quantity)));
		}
	}
}