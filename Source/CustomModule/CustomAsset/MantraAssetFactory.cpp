// Fill out your copyright notice in the Description page of Project Settings.

#include "MantraAssetFactory.h"
#include <AssetTypeCategories.h>
#include <Private/AssetTools.h>




UMantraAssetFactory::UMantraAssetFactory()
{
	// 初始化一些默认值（是否允许创建、创建完成之后是否立刻编辑、支持的类型）
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
	// 创建我们自定义的类型
	UMantraAsset* MantraAsset = NewObject<UMantraAsset>(InParent, InClass, InName, Flags);
	return MantraAsset;
}

// 右键菜单中显示的菜单名称
FText UMantraAssetFactory::GetDisplayName() const
{
	return FText::FromString("MantraAsset");
}

// 右键菜单中显示的菜单图标
FName UMantraAssetFactory::GetNewAssetThumbnailOverride() const
{
	return TEXT("ClassThumbnail.CameraAnim");
}

// 右键菜单中显示的下拉菜单分类
uint32 UMantraAssetFactory::GetMenuCategories() const
{
	return EAssetTypeCategories::Basic;
}
