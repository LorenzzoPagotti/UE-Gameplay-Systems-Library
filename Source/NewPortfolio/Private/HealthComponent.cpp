#include "HealthComponent.h"

UHealthComponent::UHealthComponent()
{
	
}

void UHealthComponent::DamagePlayer(float DamageDealt)
{
	if (bIsDead)
	{
		return; // Leaves the function if the player is already dead.
	}

	CurrentHealth = FMath::Clamp(CurrentHealth - DamageDealt, MinHealth, MaxHealth); // Clamping the health between Minimum and Maximum health possible.

	if (CurrentHealth <= MinHealth) // Checks if the player should be dead.
	{
		bIsDead = true;
		Die(); // Set IsDead to true and calls the Die function.

		OnPlayerDeath.Broadcast(GetOwner()); // Communicate the player death.
	}

	OnHealthChanged.Broadcast(CurrentHealth); // Updates the widget.

}

void UHealthComponent::HealPlayer(float HealthToRegenerate)
{
	if (bIsDead)
	{
		return; // Leaves the function if the player is already dead.
	}

	CurrentHealth = FMath::Clamp(CurrentHealth + HealthToRegenerate, MinHealth, MaxHealth); // Clamping the health between Minimum and Maximum health possible.

	OnHealthChanged.Broadcast(CurrentHealth); // Updates the Widget.
}

float UHealthComponent::GetHealthPercentage() const
{
	if (MaxHealth <= 0.0f)
	{
		return 0.0f;
	}
	return CurrentHealth / MaxHealth;
}

void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	CurrentHealth = MaxHealth;

}

void UHealthComponent::Die_Implementation()
{

}
