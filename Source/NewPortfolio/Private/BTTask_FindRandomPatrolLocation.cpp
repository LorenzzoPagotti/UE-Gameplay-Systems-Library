#include "BTTask_FindRandomPatrolLocation.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "NavigationSystem.h"

UBTTask_FindRandomPatrolLocation::UBTTask_FindRandomPatrolLocation()
{
	NodeName = "Find Random Patrol Location";
}

EBTNodeResult::Type UBTTask_FindRandomPatrolLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* OwnerController = OwnerComp.GetAIOwner();

	APawn* ControlledPawn = OwnerController->GetPawn();

	if (ControlledPawn && OwnerController)
	{
		UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetCurrent(GetWorld());

		if (NavSystem)
		{
			FNavLocation FoundLocation;

			FVector Origin = ControlledPawn->GetActorLocation();

			if (NavSystem->GetRandomPointInNavigableRadius(Origin, PatrolRadius, FoundLocation)) // checks if the function returns true (valid location)
			{
				OwnerComp.GetBlackboardComponent()->SetValueAsVector(PatrolLocationKey.SelectedKeyName, FoundLocation.Location); // set the new patrol location to the patrol key

				return EBTNodeResult::Succeeded; // Location, nav system and references valid.
			}
			else
			{
				return EBTNodeResult::Failed; // Location invalid
			}
		}
		else
		{
			return EBTNodeResult::Failed; // Nav System invalid
		}

	}
	else
	{
		return EBTNodeResult::Failed; // ControlledPawn or OwnerController invalid
	}
}
