// Lorenzzo Pagotti

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractionInterface.h"
#include "ItemType.h"
#include "BaseInventoryItem.generated.h"


class UInventoryDataAsset;

UCLASS()
class NEWPORTFOLIO_API ABaseInventoryItem : public AActor, public IInteractionInterface
{
	GENERATED_BODY()
	
public:	
	ABaseInventoryItem();

protected:

	UPROPERTY (EditAnywhere, Category = Sound)
	TObjectPtr<USoundBase> PickupSound;

	UPROPERTY (EditAnywhere, BlueprintReadOnly, Category = Item)
	TObjectPtr<UInventoryDataAsset> ItemData;

	virtual void BeginPlay() override;
	virtual void Interact_Implementation(AActor* PlayerThatInteracted) override;

public:	


};
