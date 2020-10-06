// Fill out your copyright notice in the Description page of Project Settings.


#include "GoMinionsGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Container.h"
#include "Enums.h"
#include "Container.h"

TArray<AContainer*> UGoMinionsGameInstance::GetContainers(ENeededObjectEnum NeededObjectEnumParam) {
	
	TArray<AActor*> FoundContainers;
	TArray<AContainer*> RelevantContainers;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AContainer::StaticClass(), FoundContainers);
	for (AActor* Actor : FoundContainers){
		AContainer* Container = Cast<AContainer>(Actor);
		if (Container) {
			if (Container->NeededObjectEnum == NeededObjectEnumParam) {
				RelevantContainers.Add(Container);
				
			}
		}
	}
	/*GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("RelevantContainers %d"), RelevantContainers.Num()));*/
	
	return RelevantContainers;
}

