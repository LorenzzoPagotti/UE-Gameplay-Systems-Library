#include "CustomAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AISenseConfig_Hearing.h"

ACustomAIController::ACustomAIController()
{

	MyPerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("SightPerceptionComponent"));

	UAISenseConfig_Sight* SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightConfig"));

	SightConfig->SightRadius = AISightRadius;
	SightConfig->LoseSightRadius = AILoseSightRadius;

	SightConfig->PeripheralVisionAngleDegrees = AIVisionAngleDegrees;

	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;

	MyPerceptionComponent->ConfigureSense(*SightConfig);

	MyPerceptionComponent->SetDominantSense(SightConfig->GetSenseImplementation());

	UAISenseConfig_Hearing* HearingConfig = CreateDefaultSubobject<UAISenseConfig_Hearing>(TEXT("HearingConfig"));

	HearingConfig->HearingRange = MaxHearingRange;

	HearingConfig->DetectionByAffiliation.bDetectEnemies = true;
	HearingConfig->DetectionByAffiliation.bDetectNeutrals = true;
	HearingConfig->DetectionByAffiliation.bDetectFriendlies = true;

	MyPerceptionComponent->ConfigureSense(*HearingConfig);

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

	if (Actor && Actor->ActorHasTag("Detectable"))
	{
		if (Stimulus.Type == UAISense::GetSenseID<UAISense_Sight>())
		{
			bool bSuccessfullySensed = Stimulus.WasSuccessfullySensed(); // Successfully sensed the Actor?

			if (bSuccessfullySensed)
			{
				GetBlackboardComponent()->SetValueAsObject(SensedActorKeyName, Actor); // Set the Sensed Actor blackboard key to the actor sensed
				GetBlackboardComponent()->SetValueAsBool(LineOfSightKeyName, true); // Set Line of Sight to True if the user wants to add further mechanics.
			}
			else
			{
				GetBlackboardComponent()->SetValueAsObject(SensedActorKeyName, nullptr); // Set the Sensed Actor blackboard key to null
				GetBlackboardComponent()->SetValueAsBool(LineOfSightKeyName, false); // set line of sight to false.

				FVector PlayerLocation = Stimulus.StimulusLocation;

				GetBlackboardComponent()->SetValueAsVector(LastKnownLocationKeyName, PlayerLocation);
			}
		}
		else if (Stimulus.Type == UAISense::GetSenseID<UAISense_Hearing>())
		{
			FVector StimulusTriggerLocation = Stimulus.StimulusLocation;

			GetBlackboardComponent()->SetValueAsVector(SoundLocationKeyName, StimulusTriggerLocation);
		}
	}
}
