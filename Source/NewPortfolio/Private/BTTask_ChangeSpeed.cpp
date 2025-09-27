#include "BTTask_ChangeSpeed.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "AIController.h"

UBTTask_ChangeSpeed::UBTTask_ChangeSpeed()
{
	NodeName = "Update New Walk Speed";
}

EBTNodeResult::Type UBTTask_ChangeSpeed::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* OwnerController = OwnerComp.GetAIOwner();
	if (!OwnerController)
	{
		return EBTNodeResult::Failed; // Owner Controller Failed.
	}

	APawn* ControlledPawn = OwnerController->GetPawn();
	if (!ControlledPawn)
	{
		return EBTNodeResult::Failed; // Invalid Controlled Pawn.
	}

	ACharacter* AICharacter = Cast<ACharacter>(ControlledPawn);
	if (!AICharacter)
	{
		return EBTNodeResult::Failed; // Invalid Character.
	}

	UCharacterMovementComponent* AIMovementComp = AICharacter->GetCharacterMovement();
	if (!AIMovementComp)
	{
		return EBTNodeResult::Failed; // Invalid Movement Component. 
	}

	AIMovementComp->MaxWalkSpeed = NewWalkSpeed;
	return EBTNodeResult::Succeeded; // All of the above are valid and task executed succesfully.

}
