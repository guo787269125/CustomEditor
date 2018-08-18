// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ModuleManager.h"

class FMantraCustomPinModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;


private:
	// 定义指针用于存储，方便后面卸载
	TSharedPtr<class FCustomPinFactoryt> CustomPinFactory;
};