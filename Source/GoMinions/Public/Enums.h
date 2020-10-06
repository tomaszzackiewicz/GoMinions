// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enums.generated.h"

UENUM(BlueprintType)
enum class ENeededObjectEnum : uint8 {
	NOE_1	UMETA(DisplayName = "NOE_1"),
	NOE_2	UMETA(DisplayName = "NOE_2"),
	NOE_3	UMETA(DisplayName = "NOE_3"),
	NOE_4	UMETA(DisplayName = "NOE_4"),
	NOE_5	UMETA(DisplayName = "NOE_5"),
	NOE_6	UMETA(DisplayName = "NOE_6")
};
