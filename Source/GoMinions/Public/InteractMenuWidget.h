// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enums.h"
#include "Blueprint/UserWidget.h"
#include "InteractMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class GOMINIONS_API UInteractMenuWidget : public UUserWidget{
	GENERATED_BODY()

public:

	virtual bool Initialize() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Menu", meta = (BindWidget))
	class UButton* Button_NoE_1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Menu", meta = (BindWidget))
	class UButton* Button_NoE_2;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Menu", meta = (BindWidget))
	class UButton* Button_NoE_3;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Menu", meta = (BindWidget))
	class UButton* Button_NoE_4;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Menu", meta = (BindWidget))
	class UButton* Button_NoE_5;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Menu", meta = (BindWidget))
	class UButton* Button_NoE_6;

private:

	UFUNCTION()
	void OnButton_NoE_1Clicked();

	UFUNCTION()
	void OnButton_NoE_2Clicked();

	UFUNCTION()
	void OnButton_NoE_3Clicked();

	UFUNCTION()
	void OnButton_NoE_4Clicked();

	UFUNCTION()
	void OnButton_NoE_5Clicked();

	UFUNCTION()
	void OnButton_NoE_6Clicked();

	void CloseWidget();

	void LogInformation(ENeededObjectEnum NeededObjectEnumParam);
};
