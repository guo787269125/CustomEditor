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
	// SlateĬ�ϵĹ����ʽ
	SLATE_BEGIN_ARGS(SCustomGraphPin)
	{}
	SLATE_END_ARGS()
	
		// ������EventConstruct
	void Construct(const FArguments& InArgs, UEdGraphPin* InPin);

protected:
	// ��Pin��������������ʾʲô��ɫ
	virtual FSlateColor GetPinColor() const override;

	// ���Ŵ�����Slate
	/** Get the widget we should put into the 'default value' space, shown when nothing connected */
	virtual TSharedRef<SWidget>	GetDefaultValueWidget() override;

	// ѡ����ɫ���֮��Ļص�����
	void OnColorPickerCommitted(FLinearColor SelectedColor);
};
