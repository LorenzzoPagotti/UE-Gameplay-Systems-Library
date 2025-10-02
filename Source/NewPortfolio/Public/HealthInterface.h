#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "HealthInterface.generated.h"

UINTERFACE(MinimalAPI)
class UHealthInterface : public UInterface
{
	GENERATED_BODY()
};

class NEWPORTFOLIO_API IHealthInterface
{
	GENERATED_BODY()

public:

	UFUNCTION (BlueprintImplementableEvent, BlueprintCallable, Category = Health)
	void Interface_DamagePlayer(float HealthToTake);

	UFUNCTION (BlueprintImplementableEvent, BlueprintCallable, Category = Health)
	void Interface_HealPlayer(float HealthToRegenerate);

	UFUNCTION (BlueprintImplementableEvent, BlueprintCallable, Category = Death)
	void Interface_KillPlayer();

};
