// Lorenzzo Pagotti

#include "BaseInventoryItem.h"
#include "InventoryInterface.h"
#include "Kismet/GameplayStatics.h"

ABaseInventoryItem::ABaseInventoryItem()
{
	PrimaryActorTick.bCanEverTick = false;

}

void ABaseInventoryItem::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABaseInventoryItem::Interact_Implementation(AActor* PlayerThatInteracted)
{

	if (PlayerThatInteracted && PlayerThatInteracted->Implements<UInventoryInterface>())
	{
		IInventoryInterface::Execute_Interface_AddItem(PlayerThatInteracted, ItemData);

		UGameplayStatics::PlaySoundAtLocation(GetWorld(), PickupSound, GetActorLocation());

		Destroy();
	}
}
