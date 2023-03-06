// Copyright Epic Games, Inc. All Rights Reserved.

#include "SlateWindow.h"
#include "SlateWindowStyle.h"
#include "SlateWindowCommands.h"
#include "LevelEditor.h"
#include "SMainSlate.h"
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
#include "ToolMenus.h"

static const FName SlateWindowTabName("SlateWindow");

#define LOCTEXT_NAMESPACE "FSlateWindowModule"

void FSlateWindowModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FSlateWindowStyle::Initialize();
	FSlateWindowStyle::ReloadTextures();

	FSlateWindowCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FSlateWindowCommands::Get().OpenPluginWindow,
		FExecuteAction::CreateRaw(this, &FSlateWindowModule::PluginButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FSlateWindowModule::RegisterMenus));
	
	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(SlateWindowTabName, FOnSpawnTab::CreateRaw(this, &FSlateWindowModule::OnSpawnPluginTab))
		.SetDisplayName(LOCTEXT("FSlateWindowTabTitle", "SlateWindow"))
		.SetMenuType(ETabSpawnerMenuType::Hidden);
}

void FSlateWindowModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FSlateWindowStyle::Shutdown();

	FSlateWindowCommands::Unregister();

	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(SlateWindowTabName);
}

TSharedRef<SDockTab> FSlateWindowModule::OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs)
{
	FText WidgetText = FText::Format(
		LOCTEXT("WindowWidgetText", "Add code to {0} in {1} to override this window's contents"),
		FText::FromString(TEXT("FSlateWindowModule::OnSpawnPluginTab")),
		FText::FromString(TEXT("SlateWindow.cpp"))
		);

	return SNew(SDockTab)
		[
			SNew(SMainSlate)
		];
}

void FSlateWindowModule::PluginButtonClicked()
{
	FGlobalTabmanager::Get()->TryInvokeTab(SlateWindowTabName);
}

void FSlateWindowModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FSlateWindowCommands::Get().OpenPluginWindow, PluginCommands);
		}
	}

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("Settings");
			{
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FSlateWindowCommands::Get().OpenPluginWindow));
				Entry.SetCommandList(PluginCommands);
			}
		}
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FSlateWindowModule, SlateWindow)