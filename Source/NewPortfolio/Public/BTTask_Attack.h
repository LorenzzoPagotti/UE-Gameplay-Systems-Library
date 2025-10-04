#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_Attack.generated.h"

UCLASS()
class NEWPORTFOLIO_API UBTTask_Attack : public UBTTaskNode
{
	GENERATED_BODY()

public:

	UBTTask_Attack();


protected:

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	/** This key is used to storage the target Actor key. */
	UPROPERTY(EditAnywhere, Category = "AI")
	FBlackboardKeySelector ActorKey;

	/** This is the damage that the AI can do to the player. */
	UPROPERTY (EditAnywhere, BlueprintReadOnly, Category = "Attack")
	float AttackDamage = 25.0f;

	/** The Animation asset that will play On-Attack. */
	UPROPERTY (EditAnywhere, BlueprintReadWrite, Category = "Attack")
	TObjectPtr<UAnimMontage> Animation;
	

	UFUNCTION()
	void OnAnimationFinished(UBehaviorTreeComponent* OwnerComp);


	
};
