// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "SomnambulicCore.h"

#include "ISettingsModule.h"
#include "ISettingsSection.h"
#include "ISettingsContainer.h"

#include "SomnambulicCoreConfig.h"
#define LOCTEXT_NAMESPACE "FSomnambulicCoreModule"

void FSomnambulicCoreModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		// Create the new category
		ISettingsContainerPtr SettingsContainer = SettingsModule->GetContainer("Project");

		SettingsContainer->DescribeCategory("SomnambulicCore",
			LOCTEXT("RuntimeWDCategoryName", "Plugins"),
			LOCTEXT("RuntimeWDCategoryDescription", "Base configuration for Somnambulic Core"));

		// Register the settings
		ISettingsSectionPtr SettingsSection = SettingsModule->RegisterSettings("Project", "Plugins", "SomnambulicCore Settings",
			LOCTEXT("RuntimeGeneralSettingsName", "Somnambulic Core Settings"),
			LOCTEXT("RuntimeGeneralSettingsDescription", "Base configuration for Somnambulic Core"),
			GetMutableDefault<USomnambulicCoreConfig>()
		);
	}
}

void FSomnambulicCoreModule::ShutdownModule()
{
	if (UObjectInitialized())
	{
		if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
		{
			SettingsModule->UnregisterSettings("Project", "Plugins", "Somnambulic Core Settings");
		}
	}
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FSomnambulicCoreModule, SomnambulicCore)
