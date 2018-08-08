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

	// �Զ��尴ť����¼�
	void MantraButtonClicked();
	
private:

	void AddToolbarExtension(FToolBarBuilder& Builder);
	void AddMenuExtension(FMenuBuilder& Builder);

	// ������Ӳ˵��ķ���
	void AddMantraMenuExtention(FMenuBuilder& Builder);
	

	// ������Ӱ�ť������������
	void AddMantraButtonExtention(FToolBarBuilder& Builder);


private:
	TSharedPtr<class FUICommandList> PluginCommands;

	// ��Ӱ�ť�������
	TSharedPtr<class FUICommandList> MantraButtonCommand;

};