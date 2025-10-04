#include "StaminaComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

UStaminaComponent::UStaminaComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UStaminaComponent::BeginPlay()
{
	Super::BeginPlay();

	CurrentStamina = MaxStamina; // Setting the Initial stamina to its maximum.

	ACharacter* Character = Cast<ACharacter>(GetOwner());

	if (Character)
	{
		MovementComponent = Character->GetCharacterMovement();
	}
}

void UStaminaComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (bIsSprinting)
	{
		DrainStamina(DeltaTime); // Drains while Sprinting
	}
	else
	{
		RegenStamina(DeltaTime); // Regen while NOT Sprinting
	}
	if (bIsSprinting && !bCanSprint)
	{
		StopSprinting(); // Stops the Sprint immediatly if, for some reason, the Actor is sprinting when CanSprint is false
	}

}

// Stamina Functions


void UStaminaComponent::ConsumeStamina(float StaminaToConsume)
{
	CurrentStamina = FMath::Clamp(CurrentStamina - StaminaToConsume, 0.0f, MaxStamina); // Consumes the Stamina and Clamps it to a minimum of 0 and maximum of MaxStamina.
}

float UStaminaComponent::GetCurrentStamina() const
{
	return CurrentStamina; // Returns the amount of the Stamina the Actor has. Blueprint Callable.
}

void UStaminaComponent::DrainStamina(float DeltaTime)
{
	if (!MovementComponent || MovementComponent->GetCurrentAcceleration().IsNearlyZero())
	{
			return;
	}
	CurrentStamina = FMath::Clamp(CurrentStamina - StaminaDrainRate * DeltaTime, 0.0f, MaxStamina); // Drains the Stamina and Clamps it to a minimum of 0 and maximum of MaxStamina.
	if (CurrentStamina <= 0.0f) // Stops the Sprint immediatly if the user is sprinting with 0 stamina
	{
		StopSprinting();
		bCanSprint = false;
	}
}

void UStaminaComponent::RegenStamina(float DeltaTime)
{
	CurrentStamina = FMath::Clamp(CurrentStamina + StaminaRegenRate * DeltaTime, 0.0f, MaxStamina); // Regenerates the Stamina and Clamps it to a maximum of MaxStamina.
	if (CurrentStamina >= MinStaminaToSprint) // Checks if the user Can Sprint again
	{
		bCanSprint = true;
	}
}

// Sprinting Functions

void UStaminaComponent::StartSprinting()
{
		if (bCanSprint && MovementComponent)
		{
			bIsSprinting = true;
			MovementComponent->MaxWalkSpeed = SprintSpeed;
		}
}

void UStaminaComponent::StopSprinting()
{
	if (MovementComponent)
	{
		bIsSprinting = false;
		MovementComponent->MaxWalkSpeed = WalkSpeed;
	}
}

bool UStaminaComponent::GetIsSprinting() const
{
	return bIsSprinting;
}

bool UStaminaComponent::GetCanSprint() const
{
	return bCanSprint;
}
