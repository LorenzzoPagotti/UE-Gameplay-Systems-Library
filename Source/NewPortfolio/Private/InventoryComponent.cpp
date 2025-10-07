// Lorenzzo Pagotti

#include "InventoryComponent.h"

UInventoryComponent::UInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}

void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	
}

void UInventoryComponent::Interface_AddItem_Implementation(UInventoryDataAsset* ItemInfo)
{
	if (ItemInfo)
	{
		if (Items.Num() < InventorySpace)
		{
			Items.Add(ItemInfo);
		}
		else
		{
			return;
		}
	}
	else
	{
		return;
	}

}