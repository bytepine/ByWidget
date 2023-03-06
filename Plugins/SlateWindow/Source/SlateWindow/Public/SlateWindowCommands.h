// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "SlateWindowStyle.h"

class FSlateWindowCommands : public TCommands<FSlateWindowCommands>
{
public:

	FSlateWindowCommands()
		: TCommands<FSlateWindowCommands>(TEXT("SlateWindow"), NSLOCTEXT("Contexts", "SlateWindow", "SlateWindow Plugin"), NAME_None, FSlateWindowStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > OpenPluginWindow;
};