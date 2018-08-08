// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "ToolbarExtentionStyle.h"

class FToolbarExtentionCommands : public TCommands<FToolbarExtentionCommands>
{
public:

	FToolbarExtentionCommands()
		: TCommands<FToolbarExtentionCommands>(TEXT("ToolbarExtention"), NSLOCTEXT("Contexts", "ToolbarExtention", "ToolbarExtention Plugin"), NAME_None, FToolbarExtentionStyle::GetStyleSetName())

	{
		

	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > PluginAction;

	// 定义自己的按钮显示名称和提示
	TSharedPtr< FUICommandInfo > MantraButton;
};
