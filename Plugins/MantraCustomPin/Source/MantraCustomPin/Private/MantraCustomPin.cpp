// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "MantraCustomPin.h"
#include "FCustomPinFactoryt.h"


#define LOCTEXT_NAMESPACE "FMantraCustomPinModule"

void FMantraCustomPinModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	// 初始化自定义工厂并注册到系统的Graph中
	CustomPinFactory = MakeShareable(new FCustomPinFactoryt());
	FEdGraphUtilities::RegisterVisualPinFactory(CustomPinFactory);
}

void FMantraCustomPinModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	// 取消注册
	if (CustomPinFactory.Get() != nullptr)
	{
		FEdGraphUtilities::UnregisterVisualPinFactory(CustomPinFactory);
		CustomPinFactory.Reset();
	}
		
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FMantraCustomPinModule, MantraCustomPin)