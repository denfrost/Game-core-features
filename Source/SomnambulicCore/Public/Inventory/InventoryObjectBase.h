#pragma once
#include "UObject/Object.h"
#include "Engine/Texture2D.h"

#include "InventoryObjectBase.generated.h"

UCLASS()
class SOMNAMBULICCORE_API UInventoryObjectBase : public UObject
{
	GENERATED_BODY()
public:
	FName ObjectName;

	FText ObjectDisplayName;
	FText ObjectDescription;

	UPROPERTY()
	UTexture2D * ObjectTexture = nullptr;

	void Init(UInventoryDataAsset * ItemDataAsset);
};
