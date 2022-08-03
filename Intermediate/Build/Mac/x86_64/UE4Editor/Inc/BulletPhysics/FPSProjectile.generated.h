// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FVector;
class UPrimitiveComponent;
class AActor;
struct FHitResult;
#ifdef BULLETPHYSICS_FPSProjectile_generated_h
#error "FPSProjectile.generated.h already included, missing '#pragma once' in FPSProjectile.h"
#endif
#define BULLETPHYSICS_FPSProjectile_generated_h

#define BulletPhysics_Source_BulletPhysics_FPSProjectile_h_22_SPARSE_DATA
#define BulletPhysics_Source_BulletPhysics_FPSProjectile_h_22_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execProjectileReflection); \
	DECLARE_FUNCTION(execNarrowPhaseCollisionDetection); \
	DECLARE_FUNCTION(execCalcVelocity); \
	DECLARE_FUNCTION(execBroadPhaseCollisionDetection); \
	DECLARE_FUNCTION(execCross); \
	DECLARE_FUNCTION(execCollisionDetection); \
	DECLARE_FUNCTION(execOnOverlap); \
	DECLARE_FUNCTION(execOnHit);


#define BulletPhysics_Source_BulletPhysics_FPSProjectile_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execProjectileReflection); \
	DECLARE_FUNCTION(execNarrowPhaseCollisionDetection); \
	DECLARE_FUNCTION(execCalcVelocity); \
	DECLARE_FUNCTION(execBroadPhaseCollisionDetection); \
	DECLARE_FUNCTION(execCross); \
	DECLARE_FUNCTION(execCollisionDetection); \
	DECLARE_FUNCTION(execOnOverlap); \
	DECLARE_FUNCTION(execOnHit);


#define BulletPhysics_Source_BulletPhysics_FPSProjectile_h_22_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAFPSProjectile(); \
	friend struct Z_Construct_UClass_AFPSProjectile_Statics; \
public: \
	DECLARE_CLASS(AFPSProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/BulletPhysics"), NO_API) \
	DECLARE_SERIALIZER(AFPSProjectile)


#define BulletPhysics_Source_BulletPhysics_FPSProjectile_h_22_INCLASS \
private: \
	static void StaticRegisterNativesAFPSProjectile(); \
	friend struct Z_Construct_UClass_AFPSProjectile_Statics; \
public: \
	DECLARE_CLASS(AFPSProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/BulletPhysics"), NO_API) \
	DECLARE_SERIALIZER(AFPSProjectile)


#define BulletPhysics_Source_BulletPhysics_FPSProjectile_h_22_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AFPSProjectile(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AFPSProjectile) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFPSProjectile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFPSProjectile); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFPSProjectile(AFPSProjectile&&); \
	NO_API AFPSProjectile(const AFPSProjectile&); \
public:


#define BulletPhysics_Source_BulletPhysics_FPSProjectile_h_22_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFPSProjectile(AFPSProjectile&&); \
	NO_API AFPSProjectile(const AFPSProjectile&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFPSProjectile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFPSProjectile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AFPSProjectile)


#define BulletPhysics_Source_BulletPhysics_FPSProjectile_h_22_PRIVATE_PROPERTY_OFFSET
#define BulletPhysics_Source_BulletPhysics_FPSProjectile_h_19_PROLOG
#define BulletPhysics_Source_BulletPhysics_FPSProjectile_h_22_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BulletPhysics_Source_BulletPhysics_FPSProjectile_h_22_PRIVATE_PROPERTY_OFFSET \
	BulletPhysics_Source_BulletPhysics_FPSProjectile_h_22_SPARSE_DATA \
	BulletPhysics_Source_BulletPhysics_FPSProjectile_h_22_RPC_WRAPPERS \
	BulletPhysics_Source_BulletPhysics_FPSProjectile_h_22_INCLASS \
	BulletPhysics_Source_BulletPhysics_FPSProjectile_h_22_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define BulletPhysics_Source_BulletPhysics_FPSProjectile_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BulletPhysics_Source_BulletPhysics_FPSProjectile_h_22_PRIVATE_PROPERTY_OFFSET \
	BulletPhysics_Source_BulletPhysics_FPSProjectile_h_22_SPARSE_DATA \
	BulletPhysics_Source_BulletPhysics_FPSProjectile_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	BulletPhysics_Source_BulletPhysics_FPSProjectile_h_22_INCLASS_NO_PURE_DECLS \
	BulletPhysics_Source_BulletPhysics_FPSProjectile_h_22_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> BULLETPHYSICS_API UClass* StaticClass<class AFPSProjectile>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID BulletPhysics_Source_BulletPhysics_FPSProjectile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
