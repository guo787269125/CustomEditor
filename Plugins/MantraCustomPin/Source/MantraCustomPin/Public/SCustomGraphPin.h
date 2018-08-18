// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <SGraphPin.h>

/**
 * 
 */
class MANTRACUSTOMPIN_API SCustomGraphPin : public SGraphPin
{

public:
	SLATE_BEGIN_ARGS(SCustomGraphPin)
	{}
	SLATE_END_ARGS()
	
	void Construct(const FArguments& InArgs, UEdGraphPin* InPin);

protected:
	// 
	virtual FSlateColor GetPinColor() const override;

	/** Get the widget we should put into the 'default value' space, shown when nothing connected */
	virtual TSharedRef<SWidget>	GetDefaultValueWidget() override;

	void OnColorPickerCommitted(FLinearColor SelectedColor);
};
