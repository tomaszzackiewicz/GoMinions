// Fill out your copyright notice in the Description page of Project Settings.


#include "GoMinionPlayerController.h"
#include "InteractWidget.h"
#include "Kismet/GameplayStatics.h"
#include "InteractMenuWidget.h"

AGoMinionPlayerController::AGoMinionPlayerController() {
	
}

void AGoMinionPlayerController::BeginPlay() {
	Super::BeginPlay();

	CreateInteractWidget();
	CreateInteractMenuWidget();
}

void AGoMinionPlayerController::CreateInteractWidget(){
	
	if (!InteractWidgetInstance && InteractWidgetTemplate) {
		InteractWidgetInstance = CreateWidget<UInteractWidget>(this, InteractWidgetTemplate);
	}
}

void AGoMinionPlayerController::AddInteractWidgetToViewport(){
	if (InteractWidgetInstance) {
		if (!InteractWidgetInstance->GetIsVisible()) {
			InteractWidgetInstance->AddToViewport();
			InteractWidgetInstance->SetVisibility(ESlateVisibility::Visible);
			
			FInputModeGameOnly Mode;
			SetInputMode(Mode);
			bShowMouseCursor = false;
			UGameplayStatics::SetGamePaused(GetWorld(), false);
		}
	}
}

void AGoMinionPlayerController::RemoveInteractWidgetFromViewport(){
	if (InteractWidgetInstance) {
		InteractWidgetInstance->RemoveFromParent();
		InteractWidgetInstance->SetVisibility(ESlateVisibility::Hidden);

		FInputModeGameOnly Mode;
		SetInputMode(Mode);
		bShowMouseCursor = false;
		UGameplayStatics::SetGamePaused(GetWorld(), false);

	}
}

void AGoMinionPlayerController::CreateInteractMenuWidget(){
	if (!InteractMenuWidgetInstance && InteractMenuWidgetTemplate) {
		InteractMenuWidgetInstance = CreateWidget<UInteractMenuWidget>(this, InteractMenuWidgetTemplate);
	}
}

void AGoMinionPlayerController::AddInteractWidgetMenuToViewport(){
	if (InteractMenuWidgetInstance) {
		if (!InteractMenuWidgetInstance->GetIsVisible()) {
			InteractMenuWidgetInstance->AddToViewport();
			InteractMenuWidgetInstance->SetVisibility(ESlateVisibility::Visible);

			FInputModeUIOnly Mode;
			SetInputMode(Mode);
			bShowMouseCursor = true;
			UGameplayStatics::SetGamePaused(GetWorld(), true);
		}
	}
}

void AGoMinionPlayerController::RemoveInteractWidgetMenuFromViewport(){
	if (InteractMenuWidgetInstance) {
		InteractMenuWidgetInstance->RemoveFromParent();
		InteractMenuWidgetInstance->SetVisibility(ESlateVisibility::Hidden);

		FInputModeGameOnly Mode;
		SetInputMode(Mode);
		bShowMouseCursor = false;
		UGameplayStatics::SetGamePaused(GetWorld(), false);

	}
}