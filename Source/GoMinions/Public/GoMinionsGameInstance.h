// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enums.h"
#include "Engine/GameInstance.h"
#include "GoMinionsGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class GOMINIONS_API UGoMinionsGameInstance : public UGameInstance{
	GENERATED_BODY()

public:
	TArray<class AContainer*> GetContainers(ENeededObjectEnum NeededObjectEnumParam);
		
};
