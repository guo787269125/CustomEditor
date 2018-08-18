// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "MantraAsset.h"
#include <AssetTypeActions_Base.h>
#include <EditorStyleSet.h>
#include <MultiBoxBuilder.h>
#include <UIAction.h>
#include <Animation/AnimationAsset.h>
#include <ThumbnailRendering/SceneThumbnailInfo.h>
#include "MantraAssetFactory.generated.h"

/**
 * 
 */
UCLASS()
class CUSTOMMODULE_API UMantraAssetFactory : public UFactory
{
	GENERATED_BODY()
	
public:
	// ���캯��
	UMantraAssetFactory();
	
	// ��д�����������󷽷�
	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, 
		UObject* Context, FFeedbackContext* Warn, FName CallingContext) override;

	virtual FText GetDisplayName() const override;

	virtual FName GetNewAssetThumbnailOverride() const override;

	virtual uint32 GetMenuCategories() const override;

private:
	TArray<TSharedPtr<class IAssetTypeActions>> CreatedAssetActions;

};

// ����������Դͼ��Ͳ������ࣨ��Ҫע�ᣩ
class FMantraAssetAction : public FAssetTypeActions_Base
{
	// ������Դͼ��������Ĳ˵�
	/** Returns true if this class can supply actions for InObjects. */
	virtual bool HasActions(const TArray<UObject*>& InObjects) const override
	{
		return true;
	}

	/** Generates a menubuilder for the specified objects. */
	// ��������Ĳ˵�����΢���ӣ�
	virtual void GetActions(const TArray<UObject*>& InObjects, FMenuBuilder& MenuBuilder) override
	{
		// ����ͼ��
		FSlateIcon IconBrush = FSlateIcon(FEditorStyle::GetStyleSetName(), "TextureEditor.GreenChannel", 
			"TextureEditor.GreenChannel.Small");

		// ��Ӳ˵����Ұ󶨶�Ӧ�Ĳ���
		MenuBuilder.AddMenuEntry(FText::FromString("Mantra Action"), FText::FromString("This is a mantra action"), IconBrush,
			FUIAction(FExecuteAction::CreateRaw(this, &FMantraAssetAction::OnCommandClicked)));
	}

	void OnCommandClicked()
	{
		UE_LOG(LogTemp, Warning, TEXT("This Is A Mantra Asset Action Result"));
	}

	// ������Դͼ�����ɫ��
	/** Returns the name of this type */
	virtual FText GetName() const override
	{
		return FText::FromString("NewMantraAsset");
	}

	/** Checks to see if the specified object is handled by this type. */
	virtual UClass* GetSupportedClass() const override
	{
		return UMantraAsset::StaticClass();
	}
	
	/** Returns the color associated with this type */
	virtual FColor GetTypeColor() const override
	{
		return FColor::Green;
	}

	// ��������ʵ�ֵĽӿ�
	/** Returns the categories that this asset type. The return value is one or more flags from EAssetTypeCategories.  */
	virtual uint32 GetCategories() override
	{
		return EAssetTypeCategories::Basic;
	}


	

};
