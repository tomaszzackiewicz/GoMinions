// Fill out your copyright notice in the Description page of Project Settings.


#include "Minion.h"
#include "MinionAIController.h"
#include "Kismet/GameplayStatics.h"
#include "GoMinionPlayerController.h"
#include "UObject/Class.h"

// Sets default values
AMinion::AMinion(){
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	StaticMeshVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshVisual"));
	StaticMeshVisual->AddRelativeLocation(FVector(0.0f,0.0f,-90.0f));
	StaticMeshVisual->SetRelativeScale3D(FVector(0.5f, 0.5f, 1.5f));
	StaticMeshVisual->SetupAttachment(GetMesh());

}

// Called when the game starts or when spawned
void AMinion::BeginPlay(){
	Super::BeginPlay();
}

// Called every frame
void AMinion::Tick(float DeltaTime){
	Super::Tick(DeltaTime);

}

void AMinion::SetMinionSelection(bool isSelectedParam){
	isSelectedParam ? StaticMeshVisual->SetMaterial(0, SelectMaterial) : StaticMeshVisual->SetMaterial(0, NormalMaterial);
}

void AMinion::SetNeededObjectEnum(ENeededObjectEnum NeededObjectEnumParam){
	NeededObjectEnum = NeededObjectEnumParam;
	MoveMinion();
}

ENeededObjectEnum AMinion::GetNeededObjectEnum() const{
	return NeededObjectEnum;
}

void AMinion::MoveMinion() {
	
	AMinionAIController* minionAIController = Cast<AMinionAIController>(GetController());
	if (minionAIController) {
		minionAIController->MoveMinion();
	}
}
