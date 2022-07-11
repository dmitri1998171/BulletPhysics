// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef BULLETPHYSICS_BulletComponent_generated_h
#error "BulletComponent.generated.h already included, missing '#pragma once' in BulletComponent.h"
#endif
#define BULLETPHYSICS_BulletComponent_generated_h

#define BulletPhysics_Source_BulletPhysics_BulletComponent_h_15_SPARSE_DATA
#define BulletPhysics_Source_BulletPhysics_BulletComponent_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execDrawTrajectory); \
	DECLARE_FUNCTION(execshowLog); \
	DECLARE_FUNCTION(execAddResistance);


#define BulletPhysics_Source_BulletPhysics_BulletComponent_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execDrawTrajectory); \
	DECLARE_FUNCTION(execshowLog); \
	DECLARE_FUNCTION(execAddResistance);


#define BulletPhysics_Source_BulletPhysics_BulletComponent_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUBulletComponent(); \
	friend struct Z_Construct_UClass_UBulletComponent_Statics; \
public: \
	DECLARE_CLASS(UBulletComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/BulletPhysics"), NO_API) \
	DECLARE_SERIALIZER(UBulletComponent)


#define BulletPhysics_Source_BulletPhysics_BulletComponent_h_15_INCLASS \
private: \
	static void StaticRegisterNativesUBulletComponent(); \
	friend struct Z_Construct_UClass_UBulletComponent_Statics; \
public: \
	DECLARE_CLASS(UBulletComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/BulletPhysics"), NO_API) \
	DECLARE_SERIALIZER(UBulletComponent)


#define BulletPhysics_Source_BulletPhysics_BulletComponent_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UBulletComponent(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UBulletComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UBulletComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UBulletComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UBulletComponent(UBulletComponent&&); \
	NO_API UBulletComponent(const UBulletComponent&); \
public:


#define BulletPhysics_Source_BulletPhysics_BulletComponent_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UBulletComponent(UBulletComponent&&); \
	NO_API UBulletComponent(const UBulletComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UBulletComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UBulletComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UBulletComponent)


#define BulletPhysics_Source_BulletPhysics_BulletComponent_h_15_PRIVATE_PROPERTY_OFFSET
#define BulletPhysics_Source_BulletPhysics_BulletComponent_h_12_PROLOG
#define BulletPhysics_Source_BulletPhysics_BulletComponent_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BulletPhysics_Source_BulletPhysics_BulletComponent_h_15_PRIVATE_PROPERTY_OFFSET \
	BulletPhysics_Source_BulletPhysics_BulletComponent_h_15_SPARSE_DATA \
	BulletPhysics_Source_BulletPhysics_BulletComponent_h_15_RPC_WRAPPERS \
	BulletPhysics_Source_BulletPhysics_BulletComponent_h_15_INCLASS \
	BulletPhysics_Source_BulletPhysics_BulletComponent_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define BulletPhysics_Source_BulletPhysics_BulletComponent_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BulletPhysics_Source_BulletPhysics_BulletComponent_h_15_PRIVATE_PROPERTY_OFFSET \
	BulletPhysics_Source_BulletPhysics_BulletComponent_h_15_SPARSE_DATA \
	BulletPhysics_Source_BulletPhysics_BulletComponent_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	BulletPhysics_Source_BulletPhysics_BulletComponent_h_15_INCLASS_NO_PURE_DECLS \
	BulletPhysics_Source_BulletPhysics_BulletComponent_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> BULLETPHYSICS_API UClass* StaticClass<class UBulletComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID BulletPhysics_Source_BulletPhysics_BulletComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
