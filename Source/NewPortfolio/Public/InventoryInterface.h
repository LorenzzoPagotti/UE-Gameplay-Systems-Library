// Lorenzzo Pagotti

#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InventoryDataAsset.h"
#include "InventoryInterface.generated.h"

class ABaseInventoryItem;

UINTERFACE(MinimalAPI)
class UInventoryInterface : public UInterface
{
	GENERATED_BODY()
};

class NEWPORTFOLIO_API IInventoryInterface
{
	GENERATED_BODY()

public:

	UFUNCTION (BlueprintNativeEvent, BlueprintCallable, Category = Inventory)
	void Interface_AddItem(UInventoryDataAsset* ItemData);

	UFUNCTION (BlueprintNativeEvent, BlueprintCallable, Category = Inventory)
	void Interface_RemoveItem(UInventoryDataAsset* ItemData);

	UFUNCTION (BlueprintNativeEvent, BlueprintCallable, Category = Inventory)
	void Interface_ClearInventory(UInventoryDataAsset* ItemData);
};
