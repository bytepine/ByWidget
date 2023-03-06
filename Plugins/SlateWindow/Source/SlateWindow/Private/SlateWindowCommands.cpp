// Copyright Epic Games, Inc. All Rights Reserved.

#include "SlateWindowCommands.h"

#define LOCTEXT_NAMESPACE "FSlateWindowModule"

void FSlateWindowCommands::RegisterCommands()
{
	UI_COMMAND(OpenPluginWindow, "SlateWindow", "Bring up SlateWindow window", EUserInterfaceActionType::Button, FInputGesture());
}

#undef LOCTEXT_NAMESPACE
