#include "InteractionComponent.h"
#include "InteractionInterface.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/PlayerCameraManager.h"
#include "Engine/World.h"
#include "TimerManager.h"

UInteractionComponent::UInteractionComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UInteractionComponent::BeginPlay()
{

	Super::BeginPlay();

	PlayerCameraManager = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0); // Here i initialized the Camera Manager variable as the player's camera

	GetWorld()->GetTimerManager().SetTimer(InteractionWidgetTimerHandle, this, &UInteractionComponent::CheckInteractionActor, InteractionCheckRate, true); // Call the function to check for interactable itens on the player's direction every InteractionUICheckRate seconds.
}

void UInteractionComponent::CheckInteractionActor()
{
	if (!PlayerCameraManager) // Security check.
	{
		return;
	}

	AActor* PreviousActor = InteractionActor;

	FVector LineTraceStart = PlayerCameraManager->GetCameraLocation();

	FVector LineTraceEnd = (PlayerCameraManager->GetActorForwardVector() * TraceReach) + LineTraceStart; // Making the Line Trace going forward

	FHitResult HitResult; // Saving the Hit target from the Trace in a Variable

	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(GetOwner());

	if (GetWorld()->LineTraceSingleByChannel(HitResult, LineTraceStart, LineTraceEnd, ECC_Visibility, CollisionParams))
	{
		AActor* HitActor = HitResult.GetActor(); // Storing the Hit Actor of the line trace to a Local Variable

		if (HitActor && HitActor->Implements<UInteractionInterface>()) // IMPORTANT: Here is where it all happens: It checks if the actor hit is a "interactable" actor.
		{
			InteractionActor = HitActor; // Set the Interaction Actor to the Actor the player is currently looking at (valid interactable)
		}
		else
		{
			InteractionActor = nullptr; // Not valid actor (not interactable)
		}
	}
	else
	{
		InteractionActor = nullptr; // Set the Interaction Actor to invalid if Line Trace hit void.
	}

	if (bShowInteractionUI && (InteractionActor != PreviousActor)) 
	{
		OnInteractionActorChanged.Broadcast(InteractionActor);
	}

}

void UInteractionComponent::Interaction() // The function that will be called on your Interaction Input, inside your character. 
{
	if (InteractionActor) // Security Check
	{
		IInteractionInterface::Execute_Interact(InteractionActor, GetOwner()); // Executes the function on the Actor being looked at and passes the owner reference.
	}
}