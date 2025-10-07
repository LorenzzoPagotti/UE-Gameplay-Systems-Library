// Lorenzzo Pagotti

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Engine/Engine.h"
#include "ItemType.generated.h"

USTRUCT(BlueprintType)
struct FItemData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Data")
	FText DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Data")
	FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Data")
	TObjectPtr<UTexture2D> ItemIcon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Data")
	FName ItemID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Data")
	int32 MaxStacks = 1;

};