// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef MYPROJECT2_MyProject2Character_generated_h
#error "MyProject2Character.generated.h already included, missing '#pragma once' in MyProject2Character.h"
#endif
#define MYPROJECT2_MyProject2Character_generated_h

#define MyProject2_Source_MyProject2_MyProject2Character_h_14_RPC_WRAPPERS
#define MyProject2_Source_MyProject2_MyProject2Character_h_14_RPC_WRAPPERS_NO_PURE_DECLS
#define MyProject2_Source_MyProject2_MyProject2Character_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMyProject2Character(); \
	friend MYPROJECT2_API class UClass* Z_Construct_UClass_AMyProject2Character(); \
public: \
	DECLARE_CLASS(AMyProject2Character, ACharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/MyProject2"), NO_API) \
	DECLARE_SERIALIZER(AMyProject2Character) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define MyProject2_Source_MyProject2_MyProject2Character_h_14_INCLASS \
private: \
	static void StaticRegisterNativesAMyProject2Character(); \
	friend MYPROJECT2_API class UClass* Z_Construct_UClass_AMyProject2Character(); \
public: \
	DECLARE_CLASS(AMyProject2Character, ACharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/MyProject2"), NO_API) \
	DECLARE_SERIALIZER(AMyProject2Character) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define MyProject2_Source_MyProject2_MyProject2Character_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMyProject2Character(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMyProject2Character) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyProject2Character); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyProject2Character); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMyProject2Character(AMyProject2Character&&); \
	NO_API AMyProject2Character(const AMyProject2Character&); \
public:


#define MyProject2_Source_MyProject2_MyProject2Character_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMyProject2Character(AMyProject2Character&&); \
	NO_API AMyProject2Character(const AMyProject2Character&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyProject2Character); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyProject2Character); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMyProject2Character)


#define MyProject2_Source_MyProject2_MyProject2Character_h_14_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__Mesh1P() { return STRUCT_OFFSET(AMyProject2Character, Mesh1P); } \
	FORCEINLINE static uint32 __PPO__FP_Gun() { return STRUCT_OFFSET(AMyProject2Character, FP_Gun); } \
	FORCEINLINE static uint32 __PPO__FP_MuzzleLocation() { return STRUCT_OFFSET(AMyProject2Character, FP_MuzzleLocation); } \
	FORCEINLINE static uint32 __PPO__VR_Gun() { return STRUCT_OFFSET(AMyProject2Character, VR_Gun); } \
	FORCEINLINE static uint32 __PPO__VR_MuzzleLocation() { return STRUCT_OFFSET(AMyProject2Character, VR_MuzzleLocation); } \
	FORCEINLINE static uint32 __PPO__FirstPersonCameraComponent() { return STRUCT_OFFSET(AMyProject2Character, FirstPersonCameraComponent); } \
	FORCEINLINE static uint32 __PPO__R_MotionController() { return STRUCT_OFFSET(AMyProject2Character, R_MotionController); } \
	FORCEINLINE static uint32 __PPO__L_MotionController() { return STRUCT_OFFSET(AMyProject2Character, L_MotionController); }


#define MyProject2_Source_MyProject2_MyProject2Character_h_11_PROLOG
#define MyProject2_Source_MyProject2_MyProject2Character_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	MyProject2_Source_MyProject2_MyProject2Character_h_14_PRIVATE_PROPERTY_OFFSET \
	MyProject2_Source_MyProject2_MyProject2Character_h_14_RPC_WRAPPERS \
	MyProject2_Source_MyProject2_MyProject2Character_h_14_INCLASS \
	MyProject2_Source_MyProject2_MyProject2Character_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define MyProject2_Source_MyProject2_MyProject2Character_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	MyProject2_Source_MyProject2_MyProject2Character_h_14_PRIVATE_PROPERTY_OFFSET \
	MyProject2_Source_MyProject2_MyProject2Character_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	MyProject2_Source_MyProject2_MyProject2Character_h_14_INCLASS_NO_PURE_DECLS \
	MyProject2_Source_MyProject2_MyProject2Character_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID MyProject2_Source_MyProject2_MyProject2Character_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
