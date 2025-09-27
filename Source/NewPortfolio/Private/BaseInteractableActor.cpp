#include "BaseInteractableActor.h"

ABaseInteractableActor::ABaseInteractableActor()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ABaseInteractableActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABaseInteractableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

