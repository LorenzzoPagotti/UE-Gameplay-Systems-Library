// Lorenzzo Pagotti

#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryInterface.h"
#include "InventoryDataAsset.h"
#include "InventoryComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NEWPORTFOLIO_API UInventoryComponent : public UActorComponent, public IInventoryInterface
{
	GENERATED_BODY()

public:	
	UInventoryComponent();

protected:
	virtual void BeginPlay() override;

	virtual void Interface_AddItem_Implementation(UInventoryDataAsset* ItemInfo) override;

	UPROPERTY (VisibleAnywhere, BlueprintReadOnly, Category = "Inventory")
	TArray<TObjectPtr<UInventoryDataAsset>> Items;

	UPROPERTY (EditAnywhere, BlueprintReadOnly, Category = "Inventory")
	int32 InventorySpace = 10;

public:

		
};
