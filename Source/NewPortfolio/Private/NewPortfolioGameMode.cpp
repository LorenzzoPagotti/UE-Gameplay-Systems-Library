// Copyright Epic Games, Inc. All Rights Reserved.

#include "NewPortfolioGameMode.h"
#include "NewPortfolioCharacter.h"
#include "UObject/ConstructorHelpers.h"

ANewPortfolioGameMode::ANewPortfolioGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
