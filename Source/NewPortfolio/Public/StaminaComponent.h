#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StaminaComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NEWPORTFOLIO_API UStaminaComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	UStaminaComponent();

	/** This is a Custom Function so you can use on further mechanics like dashing - you might want to consume stamina when dashing, so this function is for this. */
	UFUNCTION(BlueprintCallable, Category = Stamina)
	void ConsumeStamina(float StaminaToConsume); 

	UFUNCTION(BlueprintPure, Category = Stamina)
	float GetCurrentStamina() const;

	UFUNCTION(BlueprintCallable, Category = Sprint)
	void StartSprinting();

	UFUNCTION(BlueprintCallable, Category = Sprint)
	void StopSprinting();

	UFUNCTION(BlueprintPure, Category = Sprint)
	bool GetIsSprinting() const;

	UFUNCTION (BlueprintPure, Category = Sprint)
	bool GetCanSprint() const;

protected:

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void BeginPlay() override;

	// Stamina Variables

	/** MaxStamina determines what will be the maximum amount of Stamina that an Actor can have. */
	UPROPERTY (EditAnywhere, BlueprintReadOnly, Category = Stamina)
	float MaxStamina = 100.0f;

	/** StaminaDrainRate means how much Stamina will be decreased per second when sprinting. */
	UPROPERTY (EditAnywhere, BlueprintReadOnly, Category = Stamina)
	float StaminaDrainRate = 25.0f;

	/** StaminaRegenRate means how much Stamina will be increased per second when NOT sprinting. */
	UPROPERTY (EditAnywhere, BlueprintReadOnly, Category = Stamina)
	float StaminaRegenRate = 25.0f;

	/** MinStaminaToSprint is the stamina threshold so the player can start sprinting again after the stamina get depleted. */
	UPROPERTY (EditAnywhere, BlueprintReadOnly, Category = Stamina)
	float MinStaminaToSprint = 50.0f;

	/** WalkSpeed can be changed directly from the Editor without the need to recompile from IDE. */
	UPROPERTY (EditAnywhere, BlueprintReadOnly, Category = Sprint)
	float WalkSpeed = 300.0f;

	/** SprintSpeed can be changed directly from the Editor without the need to recompile from IDE. */
	UPROPERTY (EditAnywhere, BlueprintReadOnly, Category = Sprint)
	float SprintSpeed = 600.0f;

private:

	// Stamina Variables

	float CurrentStamina = 100.0f;

	// Stamina Functions

	void DrainStamina(float DeltaTime);

	void RegenStamina(float DeltaTime);

	// Sprinting Variables

	bool bIsSprinting = false;

	bool bCanSprint = true;

	// The CMC of the Actor;

	class UCharacterMovementComponent* MovementComponent;

};
