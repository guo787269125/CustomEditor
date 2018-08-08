// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "ToolbarExtentionCommands.h"

#define LOCTEXT_NAMESPACE "FToolbarExtentionModule"

void FToolbarExtentionCommands::RegisterCommands()
{
	UI_COMMAND(PluginAction, "ToolbarExtention", "Execute ToolbarExtention action", EUserInterfaceActionType::Button, FInputGesture());
	
	// 设置按钮显示内容和提示内容
	UI_COMMAND(MantraButton, "MantraExtention", "Execute MantraExtention action", EUserInterfaceActionType::Button, FInputGesture());

}

#undef LOCTEXT_NAMESPACE
