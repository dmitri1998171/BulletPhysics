// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BulletPhysics/BulletComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBulletComponent() {}
// Cross Module References
	BULLETPHYSICS_API UClass* Z_Construct_UClass_UBulletComponent_NoRegister();
	BULLETPHYSICS_API UClass* Z_Construct_UClass_UBulletComponent();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_BulletPhysics();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
// End Cross Module References
	DEFINE_FUNCTION(UBulletComponent::execDrawTrajectory)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->DrawTrajectory();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UBulletComponent::execshowLog)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_DeltaTime);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->showLog(Z_Param_DeltaTime);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UBulletComponent::execAddResistance)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_DeltaTime);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AddResistance(Z_Param_DeltaTime);
		P_NATIVE_END;
	}
	void UBulletComponent::StaticRegisterNativesUBulletComponent()
	{
		UClass* Class = UBulletComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AddResistance", &UBulletComponent::execAddResistance },
			{ "DrawTrajectory", &UBulletComponent::execDrawTrajectory },
			{ "showLog", &UBulletComponent::execshowLog },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UBulletComponent_AddResistance_Statics
	{
		struct BulletComponent_eventAddResistance_Parms
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
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UBulletComponent_AddResistance_Statics::NewProp_DeltaTime = { "DeltaTime", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(BulletComponent_eventAddResistance_Parms, DeltaTime), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBulletComponent_AddResistance_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBulletComponent_AddResistance_Statics::NewProp_DeltaTime,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UBulletComponent_AddResistance_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "BulletComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UBulletComponent_AddResistance_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UBulletComponent, nullptr, "AddResistance", nullptr, nullptr, sizeof(BulletComponent_eventAddResistance_Parms), Z_Construct_UFunction_UBulletComponent_AddResistance_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UBulletComponent_AddResistance_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UBulletComponent_AddResistance_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UBulletComponent_AddResistance_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UBulletComponent_AddResistance()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UBulletComponent_AddResistance_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UBulletComponent_DrawTrajectory_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UBulletComponent_DrawTrajectory_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "BulletComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UBulletComponent_DrawTrajectory_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UBulletComponent, nullptr, "DrawTrajectory", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UBulletComponent_DrawTrajectory_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UBulletComponent_DrawTrajectory_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UBulletComponent_DrawTrajectory()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UBulletComponent_DrawTrajectory_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UBulletComponent_showLog_Statics
	{
		struct BulletComponent_eventshowLog_Parms
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
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UBulletComponent_showLog_Statics::NewProp_DeltaTime = { "DeltaTime", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(BulletComponent_eventshowLog_Parms, DeltaTime), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBulletComponent_showLog_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBulletComponent_showLog_Statics::NewProp_DeltaTime,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UBulletComponent_showLog_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "BulletComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UBulletComponent_showLog_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UBulletComponent, nullptr, "showLog", nullptr, nullptr, sizeof(BulletComponent_eventshowLog_Parms), Z_Construct_UFunction_UBulletComponent_showLog_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UBulletComponent_showLog_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UBulletComponent_showLog_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UBulletComponent_showLog_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UBulletComponent_showLog()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UBulletComponent_showLog_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UBulletComponent_NoRegister()
	{
		return UBulletComponent::StaticClass();
	}
	struct Z_Construct_UClass_UBulletComponent_Statics
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
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GravityScale_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_GravityScale;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Mass_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Mass;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InitialSpeed_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_InitialSpeed;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EnableWind_MetaData[];
#endif
		static void NewProp_EnableWind_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_EnableWind;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Wind_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Wind;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AirResistance_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_AirResistance;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SquareCoef_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_SquareCoef;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UBulletComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_BulletPhysics,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UBulletComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UBulletComponent_AddResistance, "AddResistance" }, // 1031185360
		{ &Z_Construct_UFunction_UBulletComponent_DrawTrajectory, "DrawTrajectory" }, // 346492340
		{ &Z_Construct_UFunction_UBulletComponent_showLog, "showLog" }, // 3561117130
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBulletComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "BulletComponent.h" },
		{ "ModuleRelativePath", "BulletComponent.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBulletComponent_Statics::NewProp_EnableLog_MetaData[] = {
		{ "Category", "Log" },
		{ "ModuleRelativePath", "BulletComponent.h" },
	};
#endif
	void Z_Construct_UClass_UBulletComponent_Statics::NewProp_EnableLog_SetBit(void* Obj)
	{
		((UBulletComponent*)Obj)->EnableLog = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UBulletComponent_Statics::NewProp_EnableLog = { "EnableLog", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UBulletComponent), &Z_Construct_UClass_UBulletComponent_Statics::NewProp_EnableLog_SetBit, METADATA_PARAMS(Z_Construct_UClass_UBulletComponent_Statics::NewProp_EnableLog_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UBulletComponent_Statics::NewProp_EnableLog_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBulletComponent_Statics::NewProp_EnableGravity_MetaData[] = {
		{ "Category", "Physics" },
		{ "ModuleRelativePath", "BulletComponent.h" },
	};
#endif
	void Z_Construct_UClass_UBulletComponent_Statics::NewProp_EnableGravity_SetBit(void* Obj)
	{
		((UBulletComponent*)Obj)->EnableGravity = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UBulletComponent_Statics::NewProp_EnableGravity = { "EnableGravity", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UBulletComponent), &Z_Construct_UClass_UBulletComponent_Statics::NewProp_EnableGravity_SetBit, METADATA_PARAMS(Z_Construct_UClass_UBulletComponent_Statics::NewProp_EnableGravity_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UBulletComponent_Statics::NewProp_EnableGravity_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBulletComponent_Statics::NewProp_Gravity_MetaData[] = {
		{ "Category", "Physics" },
		{ "ModuleRelativePath", "BulletComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UBulletComponent_Statics::NewProp_Gravity = { "Gravity", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UBulletComponent, Gravity), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_UBulletComponent_Statics::NewProp_Gravity_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UBulletComponent_Statics::NewProp_Gravity_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBulletComponent_Statics::NewProp_GravityScale_MetaData[] = {
		{ "Category", "Physics" },
		{ "ModuleRelativePath", "BulletComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UBulletComponent_Statics::NewProp_GravityScale = { "GravityScale", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UBulletComponent, GravityScale), METADATA_PARAMS(Z_Construct_UClass_UBulletComponent_Statics::NewProp_GravityScale_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UBulletComponent_Statics::NewProp_GravityScale_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBulletComponent_Statics::NewProp_Mass_MetaData[] = {
		{ "Category", "Physics" },
		{ "ModuleRelativePath", "BulletComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UBulletComponent_Statics::NewProp_Mass = { "Mass", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UBulletComponent, Mass), METADATA_PARAMS(Z_Construct_UClass_UBulletComponent_Statics::NewProp_Mass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UBulletComponent_Statics::NewProp_Mass_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBulletComponent_Statics::NewProp_InitialSpeed_MetaData[] = {
		{ "Category", "Physics" },
		{ "Comment", "// \xd1\x81\xd1\x82\xd0\xb0\xd1\x80\xd1\x82\xd0\xbe\xd0\xb2\xd0\xb0\xd1\x8f \xd0\xa1\xd0\xba\xd0\xbe\xd1\x80\xd0\xbe\xd1\x81\xd1\x82\xd1\x8c \xd1\x81\xd0\xbd\xd0\xb0\xd1\x80\xd1\x8f\xd0\xb4\xd0\xb0 (\xd0\xb7\xd0\xb0\xd0\xb2\xd0\xb8\xd1\x81\xd0\xb8\xd1\x82 \xd0\xbe\xd1\x82 \xd1\x82\xd0\xb8\xd0\xbf\xd0\xb0 \xd0\xbe\xd1\x80\xd1\x83\xd0\xb4\xd0\xb8\xd1\x8f, \xd0\xb8\xd0\xb7 \xd0\xba\xd0\xbe\xd1\x82\xd0\xbe\xd1\x80. \xd1\x81\xd1\x82\xd1\x80\xd0\xb5\xd0\xbb\xd1\x8f\xd1\x8e\xd1\x82)\n" },
		{ "ModuleRelativePath", "BulletComponent.h" },
		{ "ToolTip", "\xd1\x81\xd1\x82\xd0\xb0\xd1\x80\xd1\x82\xd0\xbe\xd0\xb2\xd0\xb0\xd1\x8f \xd0\xa1\xd0\xba\xd0\xbe\xd1\x80\xd0\xbe\xd1\x81\xd1\x82\xd1\x8c \xd1\x81\xd0\xbd\xd0\xb0\xd1\x80\xd1\x8f\xd0\xb4\xd0\xb0 (\xd0\xb7\xd0\xb0\xd0\xb2\xd0\xb8\xd1\x81\xd0\xb8\xd1\x82 \xd0\xbe\xd1\x82 \xd1\x82\xd0\xb8\xd0\xbf\xd0\xb0 \xd0\xbe\xd1\x80\xd1\x83\xd0\xb4\xd0\xb8\xd1\x8f, \xd0\xb8\xd0\xb7 \xd0\xba\xd0\xbe\xd1\x82\xd0\xbe\xd1\x80. \xd1\x81\xd1\x82\xd1\x80\xd0\xb5\xd0\xbb\xd1\x8f\xd1\x8e\xd1\x82)" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UBulletComponent_Statics::NewProp_InitialSpeed = { "InitialSpeed", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UBulletComponent, InitialSpeed), METADATA_PARAMS(Z_Construct_UClass_UBulletComponent_Statics::NewProp_InitialSpeed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UBulletComponent_Statics::NewProp_InitialSpeed_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBulletComponent_Statics::NewProp_EnableWind_MetaData[] = {
		{ "Category", "Physics|Resistance" },
		{ "Comment", "// \xd0\x92\xd0\xb5\xd1\x82\xd0\xb5\xd1\x80\n" },
		{ "ModuleRelativePath", "BulletComponent.h" },
		{ "ToolTip", "\xd0\x92\xd0\xb5\xd1\x82\xd0\xb5\xd1\x80" },
	};
#endif
	void Z_Construct_UClass_UBulletComponent_Statics::NewProp_EnableWind_SetBit(void* Obj)
	{
		((UBulletComponent*)Obj)->EnableWind = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UBulletComponent_Statics::NewProp_EnableWind = { "EnableWind", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UBulletComponent), &Z_Construct_UClass_UBulletComponent_Statics::NewProp_EnableWind_SetBit, METADATA_PARAMS(Z_Construct_UClass_UBulletComponent_Statics::NewProp_EnableWind_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UBulletComponent_Statics::NewProp_EnableWind_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBulletComponent_Statics::NewProp_Wind_MetaData[] = {
		{ "Category", "Physics|Resistance" },
		{ "ModuleRelativePath", "BulletComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UBulletComponent_Statics::NewProp_Wind = { "Wind", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UBulletComponent, Wind), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_UBulletComponent_Statics::NewProp_Wind_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UBulletComponent_Statics::NewProp_Wind_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBulletComponent_Statics::NewProp_AirResistance_MetaData[] = {
		{ "Category", "Physics|Resistance" },
		{ "Comment", "// \xd0\xa1\xd0\xbe\xd0\xbf\xd1\x80\xd0\xbe\xd1\x82\xd0\xb8\xd0\xb2\xd0\xbb\xd0\xb5\xd0\xbd\xd0\xb8\xd0\xb5 \xd0\xb2\xd0\xbe\xd0\xb7\xd0\xb4\xd1\x83\xd1\x85\xd0\xb0\n" },
		{ "ModuleRelativePath", "BulletComponent.h" },
		{ "ToolTip", "\xd0\xa1\xd0\xbe\xd0\xbf\xd1\x80\xd0\xbe\xd1\x82\xd0\xb8\xd0\xb2\xd0\xbb\xd0\xb5\xd0\xbd\xd0\xb8\xd0\xb5 \xd0\xb2\xd0\xbe\xd0\xb7\xd0\xb4\xd1\x83\xd1\x85\xd0\xb0" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UBulletComponent_Statics::NewProp_AirResistance = { "AirResistance", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UBulletComponent, AirResistance), METADATA_PARAMS(Z_Construct_UClass_UBulletComponent_Statics::NewProp_AirResistance_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UBulletComponent_Statics::NewProp_AirResistance_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBulletComponent_Statics::NewProp_SquareCoef_MetaData[] = {
		{ "Category", "Physics|Resistance" },
		{ "Comment", "// \xd0\x9a\xd0\xbe\xd1\x8d\xd1\x84. \xd0\xbf\xd0\xbb\xd0\xbe\xd1\x89\xd0\xb0\xd0\xb4\xd0\xb8 (\xd0\xbd\xd0\xb0 \xd1\x81\xd0\xba\xd0\xbe\xd0\xbb\xd1\x8c\xd0\xba\xd0\xbe \xd1\x81\xd0\xb8\xd0\xbb\xd1\x8c\xd0\xbd\xd0\xbe \xd0\xb2\xd0\xb5\xd1\x82\xd0\xb5\xd1\x80 \xd0\xb2\xd0\xbe\xd0\xb7\xd0\xb4\xd0\xb5\xd0\xb9\xd1\x81\xd1\x82\xd0\xb2\xd1\x83\xd0\xb5\xd1\x82 \xd0\xbd\xd0\xb0 \xd0\xbe\xd0\xb1\xd1\x8a\xd0\xb5\xd0\xba\xd1\x82)\n" },
		{ "ModuleRelativePath", "BulletComponent.h" },
		{ "ToolTip", "\xd0\x9a\xd0\xbe\xd1\x8d\xd1\x84. \xd0\xbf\xd0\xbb\xd0\xbe\xd1\x89\xd0\xb0\xd0\xb4\xd0\xb8 (\xd0\xbd\xd0\xb0 \xd1\x81\xd0\xba\xd0\xbe\xd0\xbb\xd1\x8c\xd0\xba\xd0\xbe \xd1\x81\xd0\xb8\xd0\xbb\xd1\x8c\xd0\xbd\xd0\xbe \xd0\xb2\xd0\xb5\xd1\x82\xd0\xb5\xd1\x80 \xd0\xb2\xd0\xbe\xd0\xb7\xd0\xb4\xd0\xb5\xd0\xb9\xd1\x81\xd1\x82\xd0\xb2\xd1\x83\xd0\xb5\xd1\x82 \xd0\xbd\xd0\xb0 \xd0\xbe\xd0\xb1\xd1\x8a\xd0\xb5\xd0\xba\xd1\x82)" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UBulletComponent_Statics::NewProp_SquareCoef = { "SquareCoef", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UBulletComponent, SquareCoef), METADATA_PARAMS(Z_Construct_UClass_UBulletComponent_Statics::NewProp_SquareCoef_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UBulletComponent_Statics::NewProp_SquareCoef_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UBulletComponent_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBulletComponent_Statics::NewProp_EnableLog,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBulletComponent_Statics::NewProp_EnableGravity,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBulletComponent_Statics::NewProp_Gravity,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBulletComponent_Statics::NewProp_GravityScale,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBulletComponent_Statics::NewProp_Mass,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBulletComponent_Statics::NewProp_InitialSpeed,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBulletComponent_Statics::NewProp_EnableWind,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBulletComponent_Statics::NewProp_Wind,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBulletComponent_Statics::NewProp_AirResistance,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBulletComponent_Statics::NewProp_SquareCoef,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UBulletComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBulletComponent>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UBulletComponent_Statics::ClassParams = {
		&UBulletComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UBulletComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UBulletComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UBulletComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UBulletComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UBulletComponent()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UBulletComponent_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UBulletComponent, 719063976);
	template<> BULLETPHYSICS_API UClass* StaticClass<UBulletComponent>()
	{
		return UBulletComponent::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UBulletComponent(Z_Construct_UClass_UBulletComponent, &UBulletComponent::StaticClass, TEXT("/Script/BulletPhysics"), TEXT("UBulletComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UBulletComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
