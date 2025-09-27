#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_ChangeSpeed.generated.h"

class UCharacterMovementComponent;

UCLASS()
class NEWPORTFOLIO_API UBTTask_ChangeSpeed : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_ChangeSpeed();

protected:

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere, Category = Speed)
	float NewWalkSpeed = 200.0f;

};
