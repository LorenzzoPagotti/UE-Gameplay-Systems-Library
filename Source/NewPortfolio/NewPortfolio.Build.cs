// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class NewPortfolio : ModuleRules
{
	public NewPortfolio(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "AIModule", "NavigationSystem" });
	}
}
