// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enums.h"
#include "GameFramework/Character.h"
#include "Minion.generated.h"

UCLASS()
class GOMINIONS_API AMinion : public ACharacter{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMinion();

	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleDefaultsOnly, Category = "Minion")
	class UStaticMeshComponent* StaticMeshVisual;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Minion")
	ENeededObjectEnum NeededObjectEnum;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void MoveMinion();

	/** Returns StaticMesh subobject **/
	FORCEINLINE class UStaticMeshComponent* GetStaticMeshVisual() const { return StaticMeshVisual; }

	void SetMinionSelection(bool isSelectedParam);

	UPROPERTY(EditDefaultsOnly, Category = "Minion")
	UMaterialInterface* SelectMaterial;

	UPROPERTY(EditDefaultsOnly, Category = "Minion")
	UMaterialInterface* NormalMaterial;

	void SetNeededObjectEnum(ENeededObjectEnum NeededObjectEnumParam);

	ENeededObjectEnum GetNeededObjectEnum() const;
};
