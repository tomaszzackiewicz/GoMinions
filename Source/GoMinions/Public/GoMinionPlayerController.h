// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GoMinionPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class GOMINIONS_API AGoMinionPlayerController : public APlayerController{
	GENERATED_BODY()

public:

	AGoMinionPlayerController();

	UPROPERTY(BlueprintReadOnly, Category = "UI")
	class UInteractWidget* InteractWidgetInstance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	TSubclassOf<class UInteractWidget> InteractWidgetTemplate;

	void CreateInteractWidget();
	void AddInteractWidgetToViewport();
	void RemoveInteractWidgetFromViewport();

	UPROPERTY(BlueprintReadOnly, Category = "UI")
	class UInteractMenuWidget* InteractMenuWidgetInstance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	TSubclassOf<class UInteractMenuWidget> InteractMenuWidgetTemplate;

	void CreateInteractMenuWidget();
	void AddInteractWidgetMenuToViewport();
	void RemoveInteractWidgetMenuFromViewport();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
};
