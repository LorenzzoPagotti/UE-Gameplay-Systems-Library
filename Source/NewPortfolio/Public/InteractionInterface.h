#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InteractionInterface.generated.h"

UINTERFACE(MinimalAPI)
class UInteractionInterface : public UInterface
{
	GENERATED_BODY()
};

class NEWPORTFOLIO_API IInteractionInterface
{
	GENERATED_BODY()

public:

	UFUNCTION (BlueprintCallable, BlueprintImplementableEvent, Category = Interaction)
	void Interact(AActor* PlayerThatInteracted);
};
