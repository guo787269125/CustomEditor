// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CustomAsset.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class MANTRACUSTOMPIN_API UCustomAsset : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mantra)
		FLinearColor MainColor;
	
	
};
