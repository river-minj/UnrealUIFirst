#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ShopItemData.generated.h"

UCLASS()
class FIRST_API UShopItemData : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly)
	FString ItemName;

	UPROPERTY(BlueprintReadOnly)
	int32 Price;

	void Init(const FString& InName, int32 InPrice)
	{
		ItemName = InName;
		Price = InPrice;
	}
};