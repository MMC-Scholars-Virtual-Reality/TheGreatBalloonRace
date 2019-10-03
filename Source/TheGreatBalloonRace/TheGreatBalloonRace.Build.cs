using System.IO;
using UnrealBuildTool;

public class TheGreatBalloonRace : ModuleRules
{
    public TheGreatBalloonRace(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "Slate", "SlateCore", "ProceduralMeshComponent" });
        PrivateDependencyModuleNames.AddRange(new string[] { "HeadMountedDisplay", "SteamVR" });

        PublicIncludePaths.Add(Path.GetFullPath(Path.Combine(ModuleDirectory, "VRBase")));
    }
}