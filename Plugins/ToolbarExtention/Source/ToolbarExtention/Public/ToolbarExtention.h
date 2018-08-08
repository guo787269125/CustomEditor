// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ModuleManager.h"

class FToolBarBuilder;
class FMenuBuilder;

class FToolbarExtentionModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	
	/** This function will be bound to Command. */
	void PluginButtonClicked();

	// 自定义按钮点击事件
	void MantraButtonClicked();
	
private:

	void AddToolbarExtension(FToolBarBuilder& Builder);
	void AddMenuExtension(FMenuBuilder& Builder);

	// 定义添加菜单的方法
	void AddMantraMenuExtention(FMenuBuilder& Builder);
	

	// 定义添加按钮到工具栏方法
	void AddMantraButtonExtention(FToolBarBuilder& Builder);


private:
	TSharedPtr<class FUICommandList> PluginCommands;

	// 添加按钮命令变量
	TSharedPtr<class FUICommandList> MantraButtonCommand;

};