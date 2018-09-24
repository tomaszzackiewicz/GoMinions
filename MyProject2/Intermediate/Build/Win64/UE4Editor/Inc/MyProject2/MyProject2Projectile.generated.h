// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FVector;
struct FHitResult;
#ifdef MYPROJECT2_MyProject2Projectile_generated_h
#error "MyProject2Projectile.generated.h already included, missing '#pragma once' in MyProject2Projectile.h"
#endif
#define MYPROJECT2_MyProject2Projectile_generated_h

#define MyProject2_Source_MyProject2_MyProject2Projectile_h_12_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnHit) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_HitComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_STRUCT(FVector,Z_Param_NormalImpulse); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_Hit); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->OnHit(Z_Param_HitComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_NormalImpulse,Z_Param_Out_Hit); \
		P_NATIVE_END; \
	}


#define MyProject2_Source_MyProject2_MyProject2Projectile_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnHit) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_HitComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_STRUCT(FVector,Z_Param_NormalImpulse); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_Hit); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->OnHit(Z_Param_HitComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_NormalImpulse,Z_Param_Out_Hit); \
		P_NATIVE_END; \
	}


#define MyProject2_Source_MyProject2_MyProject2Projectile_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMyProject2Projectile(); \
	friend MYPROJECT2_API class UClass* Z_Construct_UClass_AMyProject2Projectile(); \
public: \
	DECLARE_CLASS(AMyProject2Projectile, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/MyProject2"), NO_API) \
	DECLARE_SERIALIZER(AMyProject2Projectile) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define MyProject2_Source_MyProject2_MyProject2Projectile_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAMyProject2Projectile(); \
	friend MYPROJECT2_API class UClass* Z_Construct_UClass_AMyProject2Projectile(); \
public: \
	DECLARE_CLASS(AMyProject2Projectile, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/MyProject2"), NO_API) \
	DECLARE_SERIALIZER(AMyProject2Projectile) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define MyProject2_Source_MyProject2_MyProject2Projectile_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMyProject2Projectile(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMyProject2Projectile) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyProject2Projectile); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyProject2Projectile); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMyProject2Projectile(AMyProject2Projectile&&); \
	NO_API AMyProject2Projectile(const AMyProject2Projectile&); \
public:


#define MyProject2_Source_MyProject2_MyProject2Projectile_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMyProject2Projectile(AMyProject2Projectile&&); \
	NO_API AMyProject2Projectile(const AMyProject2Projectile&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyProject2Projectile); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyProject2Projectile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMyProject2Projectile)


#define MyProject2_Source_MyProject2_MyProject2Projectile_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CollisionComp() { return STRUCT_OFFSET(AMyProject2Projectile, CollisionComp); } \
	FORCEINLINE static uint32 __PPO__ProjectileMovement() { return STRUCT_OFFSET(AMyProject2Projectile, ProjectileMovement); }


#define MyProject2_Source_MyProject2_MyProject2Projectile_h_9_PROLOG
#define MyProject2_Source_MyProject2_MyProject2Projectile_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	MyProject2_Source_MyProject2_MyProject2Projectile_h_12_PRIVATE_PROPERTY_OFFSET \
	MyProject2_Source_MyProject2_MyProject2Projectile_h_12_RPC_WRAPPERS \
	MyProject2_Source_MyProject2_MyProject2Projectile_h_12_INCLASS \
	MyProject2_Source_MyProject2_MyProject2Projectile_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define MyProject2_Source_MyProject2_MyProject2Projectile_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	MyProject2_Source_MyProject2_MyProject2Projectile_h_12_PRIVATE_PROPERTY_OFFSET \
	MyProject2_Source_MyProject2_MyProject2Projectile_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	MyProject2_Source_MyProject2_MyProject2Projectile_h_12_INCLASS_NO_PURE_DECLS \
	MyProject2_Source_MyProject2_MyProject2Projectile_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID MyProject2_Source_MyProject2_MyProject2Projectile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
