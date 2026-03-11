// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "InventoryItemData.generated.h"

/**
 * 
 */
UCLASS()
class FIRST_API UInventoryItemData : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadOnly)
	FString ItemName;

	UPROPERTY(BlueprintReadOnly)
	int32 Quantity;

	void Init(const FString& InName, int32 InQuantity)
	{
		ItemName = InName;
		Quantity = InQuantity;
	}
};
