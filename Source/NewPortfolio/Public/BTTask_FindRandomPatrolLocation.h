#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_FindRandomPatrolLocation.generated.h"

UCLASS()
class NEWPORTFOLIO_API UBTTask_FindRandomPatrolLocation : public UBTTaskNode
{
	GENERATED_BODY()
	

public:
	UBTTask_FindRandomPatrolLocation();

protected:

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	/** This key is used to storage the new patrol location. */
	UPROPERTY(EditAnywhere, Category = "AI")
	FBlackboardKeySelector PatrolLocationKey;

	/** Variable responsible for storaging the maximum radius the AI can find a new patrol location. */
	UPROPERTY (EditAnywhere, Category = "AI")
	float PatrolRadius = 1000.0f;
};
