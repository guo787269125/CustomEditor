// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MantraAsset.generated.h"

/**
 * 
 */
UCLASS()
class CUSTOMMODULE_API UMantraAsset : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mantra)
		FString Name;
	
};
