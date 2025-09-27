#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InteractionComponent.generated.h"

class APlayerCameraManager;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInteractionActorChanged, AActor*, NewFocusedActor);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NEWPORTFOLIO_API UInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UInteractionComponent();

	/** The MAIN FUNCTION. This should be called on the Interaction Input, inside your character. This will execute the Interaction Event on the Actor the player is looking at. */
	UFUNCTION (BlueprintCallable, Category = Interaction)
	void Interaction(); 

	/** The Event called when the InteractionActor is changed. */
	UPROPERTY(BlueprintAssignable, Category = InteractionWidget)
	FOnInteractionActorChanged OnInteractionActorChanged;


protected:

	virtual void BeginPlay() override;
	/** How far the trace reaches. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Interaction)
	float TraceReach = 250.0f;

	/** Determines the rate at which the game will check if the Player is aiming at an valid interactable actor. Lower values can be more responsive, but more performant. Don't recommend changing this. Default Value = 0.15s*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Interaction)
	float InteractionCheckRate = 0.15f;

	/** This variable defines if there should be a Widget communication between the line trace and the widget. The event is OnInteractionActorChanged. */
	UPROPERTY (EditAnywhere, BlueprintReadOnly, Category = InteractionWidget)
	bool bShowInteractionUI = true;

private:

	UPROPERTY(Transient)
	TObjectPtr<APlayerCameraManager> PlayerCameraManager; // The Camera Manager Reference to send the Line Trace

	FTimerHandle InteractionWidgetTimerHandle; // Timer Handle for the Checking loop

	/** This is the Function that is constantly checking what is the Interactable Actor that the player is looking at */
	void CheckInteractionActor();

	/* The Actor that is being stored the reference of what is the interactable actor that the player looking at */
	UPROPERTY(Transient)
	TObjectPtr<AActor> InteractionActor;
};
