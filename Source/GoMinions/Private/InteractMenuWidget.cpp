// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractMenuWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "GoMinionsCharacter.h"
#include "Minion.h"
#include "GoMinionPlayerController.h"

bool UInteractMenuWidget::Initialize() {

	bool Success = Super::Initialize();

	if (!Success) {
		return false;
	}

	if (Button_NoE_1) {
		Button_NoE_1->OnClicked.RemoveAll(this);
		Button_NoE_1->OnClicked.AddDynamic(this, &UInteractMenuWidget::OnButton_NoE_1Clicked);
	}

	if (Button_NoE_2) {
		Button_NoE_2->OnClicked.RemoveAll(this);
		Button_NoE_2->OnClicked.AddDynamic(this, &UInteractMenuWidget::OnButton_NoE_2Clicked);
	}

	if (Button_NoE_3) {
		Button_NoE_3->OnClicked.RemoveAll(this);
		Button_NoE_3->OnClicked.AddDynamic(this, &UInteractMenuWidget::OnButton_NoE_3Clicked);
	}

	if (Button_NoE_4) {
		Button_NoE_4->OnClicked.RemoveAll(this);
		Button_NoE_4->OnClicked.AddDynamic(this, &UInteractMenuWidget::OnButton_NoE_4Clicked);
	}

	if (Button_NoE_5) {
		Button_NoE_5->OnClicked.RemoveAll(this);
		Button_NoE_5->OnClicked.AddDynamic(this, &UInteractMenuWidget::OnButton_NoE_5Clicked);
	}

	if (Button_NoE_6) {
		Button_NoE_6->OnClicked.RemoveAll(this);
		Button_NoE_6->OnClicked.AddDynamic(this, &UInteractMenuWidget::OnButton_NoE_6Clicked);
	}

	return true;
}

void UInteractMenuWidget::OnButton_NoE_1Clicked(){
	AGoMinionsCharacter* goMinionsCharacter = Cast<AGoMinionsCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (goMinionsCharacter) {
		if (goMinionsCharacter->GetCurrentMinion()) {
			LogInformation(ENeededObjectEnum::NOE_1);
			goMinionsCharacter->GetCurrentMinion()->SetNeededObjectEnum(ENeededObjectEnum::NOE_1);
		}
	}
	CloseWidget();
}

void UInteractMenuWidget::OnButton_NoE_2Clicked(){
	AGoMinionsCharacter* goMinionsCharacter = Cast<AGoMinionsCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (goMinionsCharacter) {
		if (goMinionsCharacter->GetCurrentMinion()) {
			LogInformation(ENeededObjectEnum::NOE_2);
			goMinionsCharacter->GetCurrentMinion()->SetNeededObjectEnum(ENeededObjectEnum::NOE_2);
		}
	}
	CloseWidget();
}

void UInteractMenuWidget::OnButton_NoE_3Clicked(){
	AGoMinionsCharacter* goMinionsCharacter = Cast<AGoMinionsCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (goMinionsCharacter) {
		if (goMinionsCharacter->GetCurrentMinion()) {
			LogInformation(ENeededObjectEnum::NOE_3);
			goMinionsCharacter->GetCurrentMinion()->SetNeededObjectEnum(ENeededObjectEnum::NOE_3);
		}
	}
	CloseWidget();
}

void UInteractMenuWidget::OnButton_NoE_4Clicked(){
	AGoMinionsCharacter* goMinionsCharacter = Cast<AGoMinionsCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (goMinionsCharacter) {
		if (goMinionsCharacter->GetCurrentMinion()) {
			LogInformation(ENeededObjectEnum::NOE_4);
			goMinionsCharacter->GetCurrentMinion()->SetNeededObjectEnum(ENeededObjectEnum::NOE_4);
		}
	}
	CloseWidget();
}

void UInteractMenuWidget::OnButton_NoE_5Clicked(){
	AGoMinionsCharacter* goMinionsCharacter = Cast<AGoMinionsCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (goMinionsCharacter) {
		if (goMinionsCharacter->GetCurrentMinion()) {
			LogInformation(ENeededObjectEnum::NOE_5);
			goMinionsCharacter->GetCurrentMinion()->SetNeededObjectEnum(ENeededObjectEnum::NOE_5);
		}
	}
	CloseWidget();
}

void UInteractMenuWidget::OnButton_NoE_6Clicked(){
	AGoMinionsCharacter* goMinionsCharacter = Cast<AGoMinionsCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (goMinionsCharacter) {
		if (goMinionsCharacter->GetCurrentMinion()) {
			LogInformation(ENeededObjectEnum::NOE_6);
			goMinionsCharacter->GetCurrentMinion()->SetNeededObjectEnum(ENeededObjectEnum::NOE_6);
		}
	}
	CloseWidget();
}

void UInteractMenuWidget::CloseWidget() {
	AGoMinionPlayerController* goMinionPlayerController = Cast<AGoMinionPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (goMinionPlayerController) {
		goMinionPlayerController->RemoveInteractWidgetMenuFromViewport();
	}
}

void UInteractMenuWidget::LogInformation(ENeededObjectEnum NeededObjectEnumParam){
	FString EnumString = UEnum::GetValueAsString<ENeededObjectEnum>(NeededObjectEnumParam);

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, FString::Printf(TEXT("Set NeededObject %s"), *EnumString));
	UE_LOG(LogTemp, Warning, TEXT("Set NeededObject %s"), *EnumString);
}

