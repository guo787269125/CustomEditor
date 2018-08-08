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

	// �����Լ��İ�ť��ʾ���ƺ���ʾ
	TSharedPtr< FUICommandInfo > MantraButton;
};
