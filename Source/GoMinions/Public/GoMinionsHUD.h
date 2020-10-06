// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GoMinionsHUD.generated.h"

UCLASS()
class AGoMinionsHUD : public AHUD{
	GENERATED_BODY()

public:
	AGoMinionsHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

