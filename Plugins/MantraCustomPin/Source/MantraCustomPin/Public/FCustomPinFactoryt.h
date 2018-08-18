// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <EdGraphUtilities.h>
#include "CustomAsset.h"
#include "SCustomGraphPin.h"

/**
 * 
 */
class MANTRACUSTOMPIN_API FCustomPinFactoryt : public FGraphPanelPinFactory
{
public:
	
	virtual TSharedPtr<class SGraphPin> CreatePin(class UEdGraphPin* Pin) const override;
};
