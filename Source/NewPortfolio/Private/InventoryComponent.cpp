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
	Items.Add(ItemInfo);

	UE_LOG(LogTemp, Warning, TEXT("Adicionado ao inventário: %s"), *ItemInfo->ItemInformation.DisplayName.ToString());

}