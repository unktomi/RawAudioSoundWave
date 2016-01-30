// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class RawAudioEditor : ModuleRules
{
	public RawAudioEditor(TargetInfo Target)
	{
		DynamicallyLoadedModuleNames.AddRange(
			new string[] {
				"AssetTools",
				"WorkspaceMenuStructure",
			}
		);

		PrivateIncludePaths.AddRange(
			new string[] {
				"RawAudioEditor/Private",
				"RawAudioEditor/Private/AssetTools",
				"RawAudioEditor/Private/Factories",
			}
		);

		PrivateDependencyModuleNames.AddRange(
			new string[] {
				"ContentBrowser",
				"Core",
				"CoreUObject",
				"EditorStyle",
				"Engine",
				"InputCore",
				"MediaAssets",
				"PropertyEditor",
				"RenderCore",
				"RHI",
				"ShaderCore",
				"Slate",
				"SlateCore",
				"TextureEditor",
				"UnrealEd",
                                "RawAudio",
			}
		);

		PrivateIncludePathModuleNames.AddRange(
			new string[] {
				"AssetTools",
				"UnrealEd",
                                "RawAudio",
				"WorkspaceMenuStructure",
			}
		);
	}
}
