// Fill out your copyright notice in the Description page of Project Settings.

#include "FCustomPinFactoryt.h"

// ��д
TSharedPtr<class SGraphPin> FCustomPinFactoryt::CreatePin(class UEdGraphPin* Pin) const
{
	// ������UCustomAsset����ʱ��ִ�д˲���
	if (Pin->PinType.PinSubCategoryObject == UCustomAsset::StaticClass())
	{
		return SNew(SCustomGraphPin, Pin);
	}
	else
	{
		return nullptr;
	}
}
