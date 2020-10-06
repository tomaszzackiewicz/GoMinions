// Copyright Epic Games, Inc. All Rights Reserved.

#include "GoMinionsGameMode.h"
#include "GoMinionsHUD.h"
#include "GoMinionsCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGoMinionsGameMode::AGoMinionsGameMode(){
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AGoMinionsHUD::StaticClass();
}
