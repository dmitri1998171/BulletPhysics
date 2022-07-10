// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BulletPhysics/BulletPhysicsGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBulletPhysicsGameModeBase() {}
// Cross Module References
	BULLETPHYSICS_API UClass* Z_Construct_UClass_ABulletPhysicsGameModeBase_NoRegister();
	BULLETPHYSICS_API UClass* Z_Construct_UClass_ABulletPhysicsGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_BulletPhysics();
// End Cross Module References
	void ABulletPhysicsGameModeBase::StaticRegisterNativesABulletPhysicsGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_ABulletPhysicsGameModeBase_NoRegister()
	{
		return ABulletPhysicsGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_ABulletPhysicsGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ABulletPhysicsGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_BulletPhysics,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABulletPhysicsGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "BulletPhysicsGameModeBase.h" },
		{ "ModuleRelativePath", "BulletPhysicsGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ABulletPhysicsGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABulletPhysicsGameModeBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ABulletPhysicsGameModeBase_Statics::ClassParams = {
		&ABulletPhysicsGameModeBase::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_ABulletPhysicsGameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ABulletPhysicsGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ABulletPhysicsGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ABulletPhysicsGameModeBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ABulletPhysicsGameModeBase, 2830714252);
	template<> BULLETPHYSICS_API UClass* StaticClass<ABulletPhysicsGameModeBase>()
	{
		return ABulletPhysicsGameModeBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ABulletPhysicsGameModeBase(Z_Construct_UClass_ABulletPhysicsGameModeBase, &ABulletPhysicsGameModeBase::StaticClass, TEXT("/Script/BulletPhysics"), TEXT("ABulletPhysicsGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABulletPhysicsGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
