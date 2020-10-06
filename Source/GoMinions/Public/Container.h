// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enums.h"
#include "GameFramework/Actor.h"
#include "Container.generated.h"

UCLASS()
class GOMINIONS_API AContainer : public AActor{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AContainer();

	UPROPERTY(VisibleDefaultsOnly, Category = "Minion")
	class UStaticMeshComponent* StaticMeshVisual;

	UPROPERTY(VisibleDefaultsOnly, Category = "Minion")
	class UBoxComponent* Trigger;

	UPROPERTY(VisibleDefaultsOnly, Category = "Minion")
	class UTextRenderComponent* Text;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Container")
	ENeededObjectEnum NeededObjectEnum;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UFUNCTION()
	void OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnBoxEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UPROPERTY()
	class AGoMinionsCharacter* goMinionsCharacter;

	void LogInformation(class AMinion* Minion);

	bool bIsTriggered;

};
