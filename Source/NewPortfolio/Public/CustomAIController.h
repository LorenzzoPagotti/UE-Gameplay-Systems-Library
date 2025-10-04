#pragma once
#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "CustomAIController.generated.h"

class UBehaviorTree;

class UAIPerceptionComponent;

struct FAIStimulus;

UCLASS()
class NEWPORTFOLIO_API ACustomAIController : public AAIController
{
	GENERATED_BODY()

public:

	ACustomAIController();

protected:

	virtual void OnPossess(APawn* InPawn) override;

	virtual void BeginPlay() override;

	// This function will be called every time the Sense perception changes.
	UFUNCTION()
	void OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);

	// BehaviorTree and the Perception Component for the AI

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI Perceptions")
	TObjectPtr<UAIPerceptionComponent> MyPerceptionComponent;

	UPROPERTY(EditAnywhere, Category = "AI")
	TObjectPtr<UBehaviorTree> BehaviorTree;

	// Sight Sense Configuration Variables

	/** The distance that the AI can sense the player. */
	UPROPERTY(EditAnywhere, Category = "AI | Sense Config")
	float AISightRadius = 2000.0f;

	UPROPERTY(EditAnywhere, Category = "AI | Sense Config")
	float AILoseSightRadius = 2500.0f;

	/** The vision angle, on degrees, that the AI can sense the player. */
	UPROPERTY(EditAnywhere, Category = "AI | Sense Config")
	float AIVisionAngleDegrees = 90.0f;

	// Hearing Sense Configuration Variables

	UPROPERTY(EditAnywhere, Category = "AI | Hearing Config")
	float MaxHearingRange = 2000.0f;

	// Blackboard Key Variables

	/** This is the blackboard key responsible to storage the sensed actor reference. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AI | Blackboard Keys")
	FName SensedActorKeyName = "TargetPlayer";

	/** This is the blackboard key responsible to storage the answer to: Am i seeing someone? */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AI | Blackboard Keys")
	FName LineOfSightKeyName = "HasLineOfSight";

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AI | Blackboard Keys")
	FName LastKnownLocationKeyName = "LastKnownLocation";

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AI | Blackboard Keys")
	FName SoundLocationKeyName = "SoundLocation";

};