#include "CustomAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"

ACustomAIController::ACustomAIController()
{

	MyPerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("PerceptionComponent"));

	UAISenseConfig_Sight* SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightConfig"));

		SightConfig->SightRadius = AISightRadius;
		SightConfig->LoseSightRadius = AILoseSightRadius;

		SightConfig->PeripheralVisionAngleDegrees = AIVisionAngleDegrees;

		SightConfig->DetectionByAffiliation.bDetectEnemies = true;
		SightConfig->DetectionByAffiliation.bDetectNeutrals = true;
		SightConfig->DetectionByAffiliation.bDetectFriendlies = true;

	MyPerceptionComponent->ConfigureSense(*SightConfig);

	MyPerceptionComponent->SetDominantSense(SightConfig->GetSenseImplementation());

}

void ACustomAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

		if (BehaviorTree) // Security Check
		{
			RunBehaviorTree(BehaviorTree); // Initialize your Behavior Tree
		}
}

void ACustomAIController::BeginPlay()
{
	Super::BeginPlay();

	MyPerceptionComponent->OnTargetPerceptionUpdated.AddDynamic(this, &ACustomAIController::OnTargetPerceptionUpdated); // Bind the perception update change to my function

}

void ACustomAIController::OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
	bool bSuccessfullySensed = Stimulus.WasSuccessfullySensed(); // Successfully sensed the Actor?

	if (bSuccessfullySensed && Actor->ActorHasTag("Detectable")) // Sensed
	{
		GetBlackboardComponent()->SetValueAsObject(SensedActorKeyName, Actor); // Set the blackboard key to the actor sensed
		GetBlackboardComponent()->SetValueAsBool(LineOfSightKeyName, true); // Set Line of Sight to True if the user wants to add further mechanics.
	}
	else // Not Sensed (or lost the vision)
	{
		GetBlackboardComponent()->SetValueAsObject(SensedActorKeyName, nullptr); // Set the blackboard key to null
		GetBlackboardComponent()->SetValueAsBool(LineOfSightKeyName, false); // set line of sight to false.
	}
}
