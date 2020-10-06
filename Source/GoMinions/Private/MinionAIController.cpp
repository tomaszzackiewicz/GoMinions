// Fill out your copyright notice in the Description page of Project Settings.


#include "MinionAIController.h"
#include "Kismet/GameplayStatics.h"
#include "Container.h"
#include "GoMinionsGameInstance.h"
#include "Minion.h"

void AMinionAIController::MoveMinion() {
	CurrentContainer = nullptr;
	UGoMinionsGameInstance* goMinionsGameInstance = Cast<UGoMinionsGameInstance>(GetGameInstance());
	if (goMinionsGameInstance) {
		AMinion* Minion = Cast<AMinion>(this->GetPawn());
		if (Minion) {
			CurrentContainer = GetClosestActor(goMinionsGameInstance->GetContainers(Minion->GetNeededObjectEnum()));
			if (CurrentContainer) {
				LogInformation(Minion, true);
				Minion->SetMinionSelection(true);
				this->MoveToActor(CurrentContainer, 100.0f);
			}else {
				LogInformation(Minion, false);
			}
		}
	}
}

AContainer* AMinionAIController::GetClosestActor(TArray<AContainer*> Containers) {

	if (Containers.Num() <= 0) {
		return nullptr;
	}

	AContainer* closestActor = nullptr;
	float currentClosestDistance = TNumericLimits<float>::Max();

	for (int i = 0; i < Containers.Num(); i++) {
		float distance = FVector::DistSquared(this->GetPawn()->GetActorLocation(), Containers[i]->GetActorLocation());
		if (distance < currentClosestDistance) {
			currentClosestDistance = distance;
			closestActor = Containers[i];
		}
	}

	return closestActor;
}

void AMinionAIController::LogInformation(AMinion* Minion, bool isTargetParam){
	if (isTargetParam) {
		FString MinionName = Minion->GetFName().ToString();
		FString CurrentContainerName = CurrentContainer->GetFName().ToString();

		FString EnumString = UEnum::GetValueAsString<ENeededObjectEnum>(Minion->GetNeededObjectEnum());
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::Printf(TEXT("Minion %s moving to Target %s and delivering %s"), *MinionName, *CurrentContainerName, *EnumString));
		UE_LOG(LogTemp, Warning, TEXT("Minion %s moving to Target %s and delivering %s"), *MinionName, *CurrentContainerName, *EnumString);
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("NoTarget")));
		UE_LOG(LogTemp, Error, TEXT("NoTarget"));
	}
}
