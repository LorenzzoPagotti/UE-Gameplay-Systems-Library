#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChanged, float, NewHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerDeath, AActor*, DeadPlayer);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NEWPORTFOLIO_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UHealthComponent();

	/** Blueprint Custom Event that runs everytime a new health is set. */
	UPROPERTY(BlueprintAssignable, Category = HealthWidget)
	FOnHealthChanged OnHealthChanged;

	/** The blueprint custom event that runs once when the player dies. */
	UPROPERTY(BlueprintAssignable, Category = DeathWidget)
	FOnPlayerDeath OnPlayerDeath;

	/** The function that is responsible for dealing damage (take health) of the player. */
	UFUNCTION(BlueprintCallable, Category = Health)
	void DamagePlayer(float DamageDealt);

	/** The function that is responsible for regenerating health (increase health) of the player. */
	UFUNCTION(BlueprintCallable, Category = Health)
	void HealPlayer(float HealthToRegenerate);

	UFUNCTION(BlueprintPure, Category = Health)
	float GetHealthPercentage() const;

	virtual void BeginPlay() override;

protected:

	/** Maximum health possible. */
	UPROPERTY (EditAnywhere, BlueprintReadOnly, Category = Health)
	float MaxHealth = 100.0f;

	/** Minimum health possible. */
	UPROPERTY (EditAnywhere, BlueprintReadOnly, Category = Health)
	float MinHealth = 0.0f;

	/** This variable will be the health the player starts. Ideally, it should be the same as MaxHealth. It is initialized on BeginPlay. */
	UPROPERTY (BlueprintReadOnly, Category = Health)
	float CurrentHealth;

	/** Bool variable that stores the information about the player death state */
	UPROPERTY (EditAnywhere, BlueprintReadOnly, Category = Death)
	bool bIsDead = false;

	/** This function will be a blueprint implementable function. This will be called if the CurrentHealth reaches MinHealth. */
	UFUNCTION(BlueprintNativeEvent, Category = Death)
	void Die();

};
