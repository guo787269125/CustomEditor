// Fill out your copyright notice in the Description page of Project Settings.

#include "SCustomGraphPin.h"
#include <SSlider.h>
#include "CustomAsset.h"
#include <../AppFramework/Public/Widgets/Colors/SColorPicker.h>


void SCustomGraphPin::Construct(const FArguments& InArgs, UEdGraphPin* InPin)
{
	SGraphPin::Construct(SGraphPin::FArguments(), InPin);
}

FSlateColor SCustomGraphPin::GetPinColor() const
{
	return FSlateColor(FColor::White);
}

TSharedRef<SWidget> SCustomGraphPin::GetDefaultValueWidget()
{

	// 包含头文件还不够，还需要添加 AppFramework模块，否则编译报错
	return SNew(SColorPicker)
		.OnColorCommitted(this, &SCustomGraphPin::OnColorPickerCommitted);

}

void SCustomGraphPin::OnColorPickerCommitted(FLinearColor SelectedColor)
{
	UCustomAsset* CustomAsset = NewObject<UCustomAsset>(GetTransientPackage(), NAME_None);
	CustomAsset->MainColor = SelectedColor;
}


