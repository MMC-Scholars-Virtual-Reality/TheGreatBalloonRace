using System.IO;
using UnrealBuildTool;

public class TheGreatBalloonRace : ModuleRules
{
    public TheGreatBalloonRace(ReadOnlyTargetRules Target) : base(Target)
    {
        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "Slate", "SlateCore", "ProceduralMeshComponent" });
        PrivateDependencyModuleNames.AddRange(new string[] { "HeadMountedDisplay", "SteamVR" });

        PublicIncludePaths.AddRange(
            new string[]
            {
                Path.GetFullPath(Path.Combine(ModuleDirectory, "VRBase")),
                Path.GetFullPath(ModuleDirectory)
            }
        );
    }
}