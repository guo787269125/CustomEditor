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
	// Slate默认的构造格式
	SLATE_BEGIN_ARGS(SCustomGraphPin)
	{}
	SLATE_END_ARGS()
	
		// 类似于EventConstruct
	void Construct(const FArguments& InArgs, UEdGraphPin* InPin);

protected:
	// 从Pin上拉出来的线显示什么颜色
	virtual FSlateColor GetPinColor() const override;

	// 引脚创建的Slate
	/** Get the widget we should put into the 'default value' space, shown when nothing connected */
	virtual TSharedRef<SWidget>	GetDefaultValueWidget() override;

	// 选择颜色完成之后的回调函数
	void OnColorPickerCommitted(FLinearColor SelectedColor);
};
