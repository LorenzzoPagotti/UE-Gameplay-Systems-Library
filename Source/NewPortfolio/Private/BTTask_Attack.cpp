#include "BTTask_Attack.h"
#include "BehaviorTree/BehaviorTree.h"
#include "AIController.h"
#include "GameFramework/Character.h"
#include "HealthInterface.h"

#include "BehaviorTree/BlackboardComponent.h"

UBTTask_Attack::UBTTask_Attack()
{

	NodeName = "AttackPlayer";

}

EBTNodeResult::Type UBTTask_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	UObject* TempObject = OwnerComp.GetBlackboardComponent()->GetValueAsObject(ActorKey.SelectedKeyName);

	AActor* Player = Cast<AActor>(TempObject);

		if (Player && Player->Implements<UHealthInterface>())
		{
			ACharacter* AICharacter = Cast<ACharacter>(OwnerComp.GetAIOwner()->GetPawn());

			if (AICharacter && Animation)
			{

				AICharacter->PlayAnimMontage(Animation);

				float AnimDuration = Animation->GetPlayLength();

				FTimerHandle TimerHandle;
				FTimerDelegate TimerDelegate;

				TimerDelegate.BindUFunction(this, FName("OnAnimationFinished"), &OwnerComp);

				GetWorld()->GetTimerManager().SetTimer(TimerHandle, TimerDelegate, AnimDuration, false);

				return EBTNodeResult::InProgress;

			}
			else
			{
				return EBTNodeResult::Failed;
			}
		}
		else
		{
			return EBTNodeResult::Failed;
		}

}

void UBTTask_Attack::OnAnimationFinished(UBehaviorTreeComponent* OwnerComp)
{
	if (OwnerComp)
	{
		FinishLatentTask(*OwnerComp, EBTNodeResult::Succeeded);

	}
}
