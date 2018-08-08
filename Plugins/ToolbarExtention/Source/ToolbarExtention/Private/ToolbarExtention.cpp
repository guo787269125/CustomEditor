// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "ToolbarExtention.h"
#include "ToolbarExtentionStyle.h"
#include "ToolbarExtentionCommands.h"
#include "Misc/MessageDialog.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"

#include "LevelEditor.h"

static const FName ToolbarExtentionTabName("ToolbarExtention");

#define LOCTEXT_NAMESPACE "FToolbarExtentionModule"

void FToolbarExtentionModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FToolbarExtentionStyle::Initialize();
	FToolbarExtentionStyle::ReloadTextures();

	FToolbarExtentionCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FToolbarExtentionCommands::Get().PluginAction,
		FExecuteAction::CreateRaw(this, &FToolbarExtentionModule::PluginButtonClicked),
		FCanExecuteAction());

	// ��ʼ�������б�
	MantraButtonCommand = MakeShareable(new FUICommandList);
	MantraButtonCommand->MapAction(
		FToolbarExtentionCommands::Get().MantraButton,
		// �󶨰�ť����¼�
		FExecuteAction::CreateRaw(this, &FToolbarExtentionModule::MantraButtonClicked),
		FCanExecuteAction()
		);
		
	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	
	{
		TSharedPtr<FExtender> MenuExtender = MakeShareable(new FExtender());
		MenuExtender->AddMenuExtension("WindowLayout", EExtensionHook::After, PluginCommands, FMenuExtensionDelegate::CreateRaw(this, &FToolbarExtentionModule::AddMenuExtension));
		
		// ��Ӳ˵��������
		MenuExtender->AddMenuExtension("WindowLayout", EExtensionHook::After, MantraButtonCommand, 
			FMenuExtensionDelegate::CreateRaw(this, &FToolbarExtentionModule::AddMantraMenuExtention));

		LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(MenuExtender);
	}
	
	{
		TSharedPtr<FExtender> ToolbarExtender = MakeShareable(new FExtender);
		ToolbarExtender->AddToolBarExtension("Settings", EExtensionHook::After, PluginCommands, FToolBarExtensionDelegate::CreateRaw(this, &FToolbarExtentionModule::AddToolbarExtension));
		// ������ť
		ToolbarExtender->AddToolBarExtension("Settings", EExtensionHook::First, MantraButtonCommand, 
			FToolBarExtensionDelegate::CreateRaw(this, &FToolbarExtentionModule::AddMantraButtonExtention));

		LevelEditorModule.GetToolBarExtensibilityManager()->AddExtender(ToolbarExtender);
	}

	
}

void FToolbarExtentionModule::AddMenuExtension(FMenuBuilder& Builder)
{
	Builder.AddMenuEntry(FToolbarExtentionCommands::Get().PluginAction);
}

// ��Ӳ˵�
void FToolbarExtentionModule::AddMantraMenuExtention(FMenuBuilder& Builder)
{
	Builder.AddMenuEntry(FToolbarExtentionCommands::Get().MantraButton);
}

// ��Ӱ�ť
void FToolbarExtentionModule::AddMantraButtonExtention(FToolBarBuilder& Builder)
{
	Builder.AddToolBarButton(FToolbarExtentionCommands::Get().MantraButton);
}

// ��ť����¼�
void FToolbarExtentionModule::MantraButtonClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("Mantra Button Clicked"));
}

void FToolbarExtentionModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	FToolbarExtentionStyle::Shutdown();

	FToolbarExtentionCommands::Unregister();
}

void FToolbarExtentionModule::PluginButtonClicked()
{
	// Put your "OnButtonClicked" stuff here
	FText DialogText = FText::Format(
							LOCTEXT("PluginButtonDialogText", "Add code to {0} in {1} to override this button's actions"),
							FText::FromString(TEXT("FToolbarExtentionModule::PluginButtonClicked()")),
							FText::FromString(TEXT("ToolbarExtention.cpp"))
					   );
	FMessageDialog::Open(EAppMsgType::Ok, DialogText);
}








void FToolbarExtentionModule::AddToolbarExtension(FToolBarBuilder& Builder)
{
	Builder.AddToolBarButton(FToolbarExtentionCommands::Get().PluginAction);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FToolbarExtentionModule, ToolbarExtention)