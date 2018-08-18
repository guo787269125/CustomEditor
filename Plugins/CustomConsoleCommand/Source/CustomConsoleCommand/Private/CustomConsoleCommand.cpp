// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "CustomConsoleCommand.h"
#include <IConsoleManager.h>

#define LOCTEXT_NAMESPACE "FCustomConsoleCommandModule"

void FCustomConsoleCommandModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	// ´´½¨ÃüÁî²¢°ó¶¨(ÃüÁîÃû³Æ¡¢ÃüÁî°ïÖú¡¢ÃüÁîÎ¯ÍĞ)
	DisplayTestCommand = IConsoleManager::Get().RegisterConsoleCommand(TEXT("Display Custom Command"), 
		TEXT("This is a custom command created by Mantra"),
		FConsoleCommandDelegate::CreateRaw(this, &FCustomConsoleCommandModule::DisplayWindow, FString("Test Command Window"))
		);
}

void FCustomConsoleCommandModule::ShutdownModule()
{
	// Ğ¶ÔØÃüÁî
	if (DisplayTestCommand) IConsoleManager::Get().UnregisterConsoleObject(DisplayTestCommand);
}

void FCustomConsoleCommandModule::DisplayWindow(FString WindoeTitle)
{
	UE_LOG(LogTemp, Warning, TEXT("This ia a custom window command result"));
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FCustomConsoleCommandModule, CustomConsoleCommand)