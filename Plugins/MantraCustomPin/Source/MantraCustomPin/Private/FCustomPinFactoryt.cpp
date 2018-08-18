// Fill out your copyright notice in the Description page of Project Settings.

#include "FCustomPinFactoryt.h"

// 重写
TSharedPtr<class SGraphPin> FCustomPinFactoryt::CreatePin(class UEdGraphPin* Pin) const
{
	// 必须是UCustomAsset类型时才执行此操作
	if (Pin->PinType.PinSubCategoryObject == UCustomAsset::StaticClass())
	{
		return SNew(SCustomGraphPin, Pin);
	}
	else
	{
		return nullptr;
	}
}
