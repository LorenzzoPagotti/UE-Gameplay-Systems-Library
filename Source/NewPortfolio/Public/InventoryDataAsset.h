// Lorenzzo Pagotti

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ItemType.h"
#include "InventoryDataAsset.generated.h"

UCLASS()
class NEWPORTFOLIO_API UInventoryDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY (EditAnywhere, BlueprintReadOnly, Category = "Item Data")
	FItemData ItemInformation;
	


};
