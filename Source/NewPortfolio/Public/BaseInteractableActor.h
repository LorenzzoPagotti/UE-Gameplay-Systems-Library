#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractionInterface.h"
#include "BaseInteractableActor.generated.h"

UCLASS()
class NEWPORTFOLIO_API ABaseInteractableActor : public AActor, public IInteractionInterface
{
	GENERATED_BODY()
	
public:	
	ABaseInteractableActor();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
