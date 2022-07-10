// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BulletPhysics/ProjectileComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeProjectileComponent() {}
// Cross Module References
	BULLETPHYSICS_API UClass* Z_Construct_UClass_UProjectileComponent_NoRegister();
	BULLETPHYSICS_API UClass* Z_Construct_UClass_UProjectileComponent();
	ENGINE_API UClass* Z_Construct_UClass_UMovementComponent();
	UPackage* Z_Construct_UPackage__Script_BulletPhysics();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
// End Cross Module References
	DEFINE_FUNCTION(UProjectileComponent::execCalculateValues)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->CalculateValues();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UProjectileComponent::execshowLog)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_DeltaTime);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->showLog(Z_Param_DeltaTime);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UProjectileComponent::execUseGravity)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UseGravity();
		P_NATIVE_END;
	}
	void UProjectileComponent::StaticRegisterNativesUProjectileComponent()
	{
		UClass* Class = UProjectileComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CalculateValues", &UProjectileComponent::execCalculateValues },
			{ "showLog", &UProjectileComponent::execshowLog },
			{ "UseGravity", &UProjectileComponent::execUseGravity },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UProjectileComponent_CalculateValues_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UProjectileComponent_CalculateValues_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ProjectileComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UProjectileComponent_CalculateValues_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UProjectileComponent, nullptr, "CalculateValues", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UProjectileComponent_CalculateValues_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UProjectileComponent_CalculateValues_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UProjectileComponent_CalculateValues()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UProjectileComponent_CalculateValues_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UProjectileComponent_showLog_Statics
	{
		struct ProjectileComponent_eventshowLog_Parms
		{
			float DeltaTime;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_DeltaTime;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UProjectileComponent_showLog_Statics::NewProp_DeltaTime = { "DeltaTime", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ProjectileComponent_eventshowLog_Parms, DeltaTime), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UProjectileComponent_showLog_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UProjectileComponent_showLog_Statics::NewProp_DeltaTime,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UProjectileComponent_showLog_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ProjectileComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UProjectileComponent_showLog_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UProjectileComponent, nullptr, "showLog", nullptr, nullptr, sizeof(ProjectileComponent_eventshowLog_Parms), Z_Construct_UFunction_UProjectileComponent_showLog_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UProjectileComponent_showLog_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UProjectileComponent_showLog_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UProjectileComponent_showLog_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UProjectileComponent_showLog()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UProjectileComponent_showLog_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UProjectileComponent_UseGravity_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UProjectileComponent_UseGravity_Statics::Function_MetaDataParams[] = {
		{ "Comment", "// Sk - \xd0\xba\xd0\xbe\xd1\x8d\xd1\x84. \xd0\xbf\xd0\xbb\xd0\xbe\xd1\x89\xd0\xb0\xd0\xb4\xd0\xb8 (\xd0\xbd\xd0\xb0 \xd1\x81\xd0\xba\xd0\xbe\xd0\xbb\xd1\x8c\xd0\xba\xd0\xbe \xd0\xb2\xd0\xb5\xd1\x82\xd0\xb5\xd1\x80 \xd0\xb2\xd0\xbe\xd0\xb7\xd0\xb4\xd0\xb5\xd0\xb9\xd1\x81\xd1\x82\xd0\xb2\xd1\x83\xd0\xb5\xd1\x82 \xd0\xbd\xd0\xb0 \xd0\xbe\xd0\xb1\xd1\x8a\xd0\xb5\xd0\xba\xd1\x82)\n" },
		{ "ModuleRelativePath", "ProjectileComponent.h" },
		{ "ToolTip", "Sk - \xd0\xba\xd0\xbe\xd1\x8d\xd1\x84. \xd0\xbf\xd0\xbb\xd0\xbe\xd1\x89\xd0\xb0\xd0\xb4\xd0\xb8 (\xd0\xbd\xd0\xb0 \xd1\x81\xd0\xba\xd0\xbe\xd0\xbb\xd1\x8c\xd0\xba\xd0\xbe \xd0\xb2\xd0\xb5\xd1\x82\xd0\xb5\xd1\x80 \xd0\xb2\xd0\xbe\xd0\xb7\xd0\xb4\xd0\xb5\xd0\xb9\xd1\x81\xd1\x82\xd0\xb2\xd1\x83\xd0\xb5\xd1\x82 \xd0\xbd\xd0\xb0 \xd0\xbe\xd0\xb1\xd1\x8a\xd0\xb5\xd0\xba\xd1\x82)" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UProjectileComponent_UseGravity_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UProjectileComponent, nullptr, "UseGravity", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UProjectileComponent_UseGravity_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UProjectileComponent_UseGravity_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UProjectileComponent_UseGravity()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UProjectileComponent_UseGravity_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UProjectileComponent_NoRegister()
	{
		return UProjectileComponent::StaticClass();
	}
	struct Z_Construct_UClass_UProjectileComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EnableLog_MetaData[];
#endif
		static void NewProp_EnableLog_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_EnableLog;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EnableGravity_MetaData[];
#endif
		static void NewProp_EnableGravity_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_EnableGravity;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Gravity_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Gravity;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Mass_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Mass;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AirResist_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_AirResist;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Wind_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Wind;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Sk_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Sk;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UProjectileComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UMovementComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_BulletPhysics,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UProjectileComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UProjectileComponent_CalculateValues, "CalculateValues" }, // 851382528
		{ &Z_Construct_UFunction_UProjectileComponent_showLog, "showLog" }, // 2056167792
		{ &Z_Construct_UFunction_UProjectileComponent_UseGravity, "UseGravity" }, // 3492979324
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UProjectileComponent_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "ProjectileComponent.h" },
		{ "ModuleRelativePath", "ProjectileComponent.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UProjectileComponent_Statics::NewProp_EnableLog_MetaData[] = {
		{ "Category", "Log" },
		{ "ModuleRelativePath", "ProjectileComponent.h" },
	};
#endif
	void Z_Construct_UClass_UProjectileComponent_Statics::NewProp_EnableLog_SetBit(void* Obj)
	{
		((UProjectileComponent*)Obj)->EnableLog = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UProjectileComponent_Statics::NewProp_EnableLog = { "EnableLog", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UProjectileComponent), &Z_Construct_UClass_UProjectileComponent_Statics::NewProp_EnableLog_SetBit, METADATA_PARAMS(Z_Construct_UClass_UProjectileComponent_Statics::NewProp_EnableLog_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UProjectileComponent_Statics::NewProp_EnableLog_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UProjectileComponent_Statics::NewProp_EnableGravity_MetaData[] = {
		{ "Category", "Physics" },
		{ "ModuleRelativePath", "ProjectileComponent.h" },
	};
#endif
	void Z_Construct_UClass_UProjectileComponent_Statics::NewProp_EnableGravity_SetBit(void* Obj)
	{
		((UProjectileComponent*)Obj)->EnableGravity = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UProjectileComponent_Statics::NewProp_EnableGravity = { "EnableGravity", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UProjectileComponent), &Z_Construct_UClass_UProjectileComponent_Statics::NewProp_EnableGravity_SetBit, METADATA_PARAMS(Z_Construct_UClass_UProjectileComponent_Statics::NewProp_EnableGravity_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UProjectileComponent_Statics::NewProp_EnableGravity_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UProjectileComponent_Statics::NewProp_Gravity_MetaData[] = {
		{ "Category", "Physics" },
		{ "ModuleRelativePath", "ProjectileComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UProjectileComponent_Statics::NewProp_Gravity = { "Gravity", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UProjectileComponent, Gravity), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_UProjectileComponent_Statics::NewProp_Gravity_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UProjectileComponent_Statics::NewProp_Gravity_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UProjectileComponent_Statics::NewProp_Mass_MetaData[] = {
		{ "Category", "Physics|Material" },
		{ "ModuleRelativePath", "ProjectileComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UProjectileComponent_Statics::NewProp_Mass = { "Mass", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UProjectileComponent, Mass), METADATA_PARAMS(Z_Construct_UClass_UProjectileComponent_Statics::NewProp_Mass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UProjectileComponent_Statics::NewProp_Mass_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UProjectileComponent_Statics::NewProp_AirResist_MetaData[] = {
		{ "Category", "Physics" },
		{ "Comment", "//    UPROPERTY(EditAnywhere, Category = \"Physics\")\n//    FVector Velocity;     // \xd1\x81\xd1\x82\xd0\xb0\xd1\x80\xd1\x82\xd0\xbe\xd0\xb2\xd0\xb0\xd1\x8f \xd0\xa1\xd0\xba\xd0\xbe\xd1\x80\xd0\xbe\xd1\x81\xd1\x82\xd1\x8c \xd1\x81\xd0\xbd\xd0\xb0\xd1\x80\xd1\x8f\xd0\xb4\xd0\xb0 (\xd0\xb7\xd0\xb0\xd0\xb2\xd0\xb8\xd1\x81\xd0\xb8\xd1\x82 \xd0\xbe\xd1\x82 \xd1\x82\xd0\xb8\xd0\xbf\xd0\xb0 \xd0\xbe\xd1\x80\xd1\x83\xd0\xb4\xd0\xb8\xd1\x8f, \xd0\xb8\xd0\xb7 \xd0\xba\xd0\xbe\xd1\x82\xd0\xbe\xd1\x80. \xd1\x81\xd1\x82\xd1\x80\xd0\xb5\xd0\xbb\xd1\x8f\xd1\x8e\xd1\x82)\n" },
		{ "ModuleRelativePath", "ProjectileComponent.h" },
		{ "ToolTip", "UPROPERTY(EditAnywhere, Category = \"Physics\")\nFVector Velocity;      \xd1\x81\xd1\x82\xd0\xb0\xd1\x80\xd1\x82\xd0\xbe\xd0\xb2\xd0\xb0\xd1\x8f \xd0\xa1\xd0\xba\xd0\xbe\xd1\x80\xd0\xbe\xd1\x81\xd1\x82\xd1\x8c \xd1\x81\xd0\xbd\xd0\xb0\xd1\x80\xd1\x8f\xd0\xb4\xd0\xb0 (\xd0\xb7\xd0\xb0\xd0\xb2\xd0\xb8\xd1\x81\xd0\xb8\xd1\x82 \xd0\xbe\xd1\x82 \xd1\x82\xd0\xb8\xd0\xbf\xd0\xb0 \xd0\xbe\xd1\x80\xd1\x83\xd0\xb4\xd0\xb8\xd1\x8f, \xd0\xb8\xd0\xb7 \xd0\xba\xd0\xbe\xd1\x82\xd0\xbe\xd1\x80. \xd1\x81\xd1\x82\xd1\x80\xd0\xb5\xd0\xbb\xd1\x8f\xd1\x8e\xd1\x82)" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UProjectileComponent_Statics::NewProp_AirResist = { "AirResist", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UProjectileComponent, AirResist), METADATA_PARAMS(Z_Construct_UClass_UProjectileComponent_Statics::NewProp_AirResist_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UProjectileComponent_Statics::NewProp_AirResist_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UProjectileComponent_Statics::NewProp_Wind_MetaData[] = {
		{ "Category", "Physics" },
		{ "Comment", "// \xd0\xa1\xd0\xbe\xd0\xbf\xd1\x80\xd0\xbe\xd1\x82\xd0\xb8\xd0\xb2\xd0\xbb\xd0\xb5\xd0\xbd\xd0\xb8\xd0\xb5 \xd0\xb2\xd0\xbe\xd0\xb7\xd0\xb4\xd1\x83\xd1\x85\xd0\xb0\n" },
		{ "ModuleRelativePath", "ProjectileComponent.h" },
		{ "ToolTip", "\xd0\xa1\xd0\xbe\xd0\xbf\xd1\x80\xd0\xbe\xd1\x82\xd0\xb8\xd0\xb2\xd0\xbb\xd0\xb5\xd0\xbd\xd0\xb8\xd0\xb5 \xd0\xb2\xd0\xbe\xd0\xb7\xd0\xb4\xd1\x83\xd1\x85\xd0\xb0" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UProjectileComponent_Statics::NewProp_Wind = { "Wind", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UProjectileComponent, Wind), METADATA_PARAMS(Z_Construct_UClass_UProjectileComponent_Statics::NewProp_Wind_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UProjectileComponent_Statics::NewProp_Wind_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UProjectileComponent_Statics::NewProp_Sk_MetaData[] = {
		{ "Category", "Physics" },
		{ "Comment", "// \xd0\x92\xd0\xb5\xd1\x82\xd0\xb5\xd1\x80\n" },
		{ "ModuleRelativePath", "ProjectileComponent.h" },
		{ "ToolTip", "\xd0\x92\xd0\xb5\xd1\x82\xd0\xb5\xd1\x80" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UProjectileComponent_Statics::NewProp_Sk = { "Sk", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UProjectileComponent, Sk), METADATA_PARAMS(Z_Construct_UClass_UProjectileComponent_Statics::NewProp_Sk_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UProjectileComponent_Statics::NewProp_Sk_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UProjectileComponent_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UProjectileComponent_Statics::NewProp_EnableLog,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UProjectileComponent_Statics::NewProp_EnableGravity,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UProjectileComponent_Statics::NewProp_Gravity,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UProjectileComponent_Statics::NewProp_Mass,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UProjectileComponent_Statics::NewProp_AirResist,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UProjectileComponent_Statics::NewProp_Wind,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UProjectileComponent_Statics::NewProp_Sk,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UProjectileComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UProjectileComponent>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UProjectileComponent_Statics::ClassParams = {
		&UProjectileComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UProjectileComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UProjectileComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UProjectileComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UProjectileComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UProjectileComponent()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UProjectileComponent_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UProjectileComponent, 3876821564);
	template<> BULLETPHYSICS_API UClass* StaticClass<UProjectileComponent>()
	{
		return UProjectileComponent::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UProjectileComponent(Z_Construct_UClass_UProjectileComponent, &UProjectileComponent::StaticClass, TEXT("/Script/BulletPhysics"), TEXT("UProjectileComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UProjectileComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
