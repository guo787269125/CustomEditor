// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "ToolbarExtention.h"
#include "ToolbarExtentionStyle.h"
#include "ToolbarExtentionCommands.h"
#include "Misc/MessageDialog.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"

#include "LevelEditor.h"
#include <../MainFrame/Public/Interfaces/IMainFrameModule.h>
#include <SlateApplication.h>

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

	// 初始化命令列表
	MantraButtonCommand = MakeShareable(new FUICommandList);
	MantraButtonCommand->MapAction(
		FToolbarExtentionCommands::Get().MantraButton,
		// 绑定按钮点击事件
		FExecuteAction::CreateRaw(this, &FToolbarExtentionModule::MantraButtonClicked),
		FCanExecuteAction()
		);
		
	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	
	{
		TSharedPtr<FExtender> MenuExtender = MakeShareable(new FExtender());
		MenuExtender->AddMenuExtension("WindowLayout", EExtensionHook::After, PluginCommands, FMenuExtensionDelegate::CreateRaw(this, &FToolbarExtentionModule::AddMenuExtension));
		
		// 添加菜单点击操作
		MenuExtender->AddMenuExtension("WindowLayout", EExtensionHook::After, MantraButtonCommand, 
			FMenuExtensionDelegate::CreateRaw(this, &FToolbarExtentionModule::AddMantraMenuExtention));

		LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(MenuExtender);
	}
	
	{
		TSharedPtr<FExtender> ToolbarExtender = MakeShareable(new FExtender);
		ToolbarExtender->AddToolBarExtension("Settings", EExtensionHook::After, PluginCommands, FToolBarExtensionDelegate::CreateRaw(this, &FToolbarExtentionModule::AddToolbarExtension));
		// 添加命令按钮
		ToolbarExtender->AddToolBarExtension("Settings", EExtensionHook::First, MantraButtonCommand, 
			FToolBarExtensionDelegate::CreateRaw(this, &FToolbarExtentionModule::AddMantraButtonExtention));

		LevelEditorModule.GetToolBarExtensibilityManager()->AddExtender(ToolbarExtender);
	}

	
}

void FToolbarExtentionModule::AddMenuExtension(FMenuBuilder& Builder)
{
	Builder.AddMenuEntry(FToolbarExtentionCommands::Get().PluginAction);
}

// 添加菜单
void FToolbarExtentionModule::AddMantraMenuExtention(FMenuBuilder& Builder)
{
	Builder.AddMenuEntry(FToolbarExtentionCommands::Get().MantraButton);
}

// 添加按钮
void FToolbarExtentionModule::AddMantraButtonExtention(FToolBarBuilder& Builder)
{
	Builder.AddToolBarButton(FToolbarExtentionCommands::Get().MantraButton);
}

// 按钮点击事件
void FToolbarExtentionModule::MantraButtonClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("Mantra Button Clicked"));

	// 点击按钮之后打开一个窗口
	// 1 创建窗口
	TSharedPtr<SWindow> MantraWindow = SNew(SWindow)
		.Title(FText::FromString("Mantra Window"))
		.ClientSize(FVector2D(800, 400))
		.SupportsMaximize(true)
		.SupportsMinimize(true)
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
			.HAlign(EHorizontalAlignment::HAlign_Center)
			.VAlign(EVerticalAlignment::VAlign_Center)
			[
				SNew(STextBlock)
				.Text(FText::FromString("Hello, Mantra"))
			]
		];

	// 2 添加和显示窗口
	// 如果有父窗口则添加为子窗口，否则直接添加
	IMainFrameModule& MainFrameModule = FModuleManager::LoadModuleChecked<IMainFrameModule>("MainFrame");
	UE_LOG(LogTemp, Warning, TEXT("Loaded Module"));

	if (MainFrameModule.GetParentWindow().IsValid())
	{
		FSlateApplication::Get().AddWindowAsNativeChild(MantraWindow.ToSharedRef(), MainFrameModule.GetParentWindow().ToSharedRef());
	}
	else
	{
		FSlateApplication::Get().AddWindow(MantraWindow.ToSharedRef());
	}
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