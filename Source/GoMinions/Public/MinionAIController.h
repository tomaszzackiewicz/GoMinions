// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "MinionAIController.generated.h"

/**
 * 
 */
UCLASS()
class GOMINIONS_API AMinionAIController : public AAIController{
	GENERATED_BODY()

public:
	void MoveMinion();

	UPROPERTY(VisibleAnywhere, Category = "Minion")
	class AContainer* CurrentContainer;

private:
	class AContainer* GetClosestActor(TArray<AContainer*> Containers);

	void LogInformation(class AMinion* Minion, bool isTargetParam);
	
};
