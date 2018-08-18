// Fill out your copyright notice in the Description page of Project Settings.

#include "MantraAssetFactory.h"
#include <AssetTypeCategories.h>
#include <Private/AssetTools.h>




UMantraAssetFactory::UMantraAssetFactory()
{
	// ��ʼ��һЩĬ��ֵ���Ƿ����������������֮���Ƿ����̱༭��֧�ֵ����ͣ�
	bCreateNew = true;
	bEditAfterNew = true;
	SupportedClass = UMantraAsset::StaticClass();

	IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
	auto MantraAssetAction = MakeShareable(new FMantraAssetAction);
	AssetTools.RegisterAssetTypeActions(MantraAssetAction);

}

UObject* UMantraAssetFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, 
	EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn, FName CallingContext)
{
	// ���������Զ��������
	UMantraAsset* MantraAsset = NewObject<UMantraAsset>(InParent, InClass, InName, Flags);
	return MantraAsset;
}

// �Ҽ��˵�����ʾ�Ĳ˵�����
FText UMantraAssetFactory::GetDisplayName() const
{
	return FText::FromString("MantraAsset");
}

// �Ҽ��˵�����ʾ�Ĳ˵�ͼ��
FName UMantraAssetFactory::GetNewAssetThumbnailOverride() const
{
	return TEXT("ClassThumbnail.CameraAnim");
}

// �Ҽ��˵�����ʾ�������˵�����
uint32 UMantraAssetFactory::GetMenuCategories() const
{
	return EAssetTypeCategories::Basic;
}
