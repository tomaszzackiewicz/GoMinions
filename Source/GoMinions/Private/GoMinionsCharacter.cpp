// Copyright Epic Games, Inc. All Rights Reserved.

#include "GoMinionsCharacter.h"
#include "GoMinionsProjectile.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/InputSettings.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "MotionControllerComponent.h"
#include "XRMotionControllerBase.h" // for FXRMotionControllerBase::RightHandSourceId
#include "GoMinionsprojectile.h"
#include "Minion.h"
#include "GoMinionPlayerController.h"
#include "Floor.h"

DEFINE_LOG_CATEGORY_STATIC(LogFPChar, Warning, All);

//////////////////////////////////////////////////////////////////////////
// AGoMinionsCharacter

AGoMinionsCharacter::AGoMinionsCharacter(){
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->SetRelativeLocation(FVector(-39.56f, 1.75f, 64.f)); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	Mesh1P->SetOnlyOwnerSee(true);
	Mesh1P->SetupAttachment(FirstPersonCameraComponent);
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->CastShadow = false;
	Mesh1P->SetRelativeRotation(FRotator(1.9f, -19.19f, 5.2f));
	Mesh1P->SetRelativeLocation(FVector(-0.5f, -4.4f, -155.7f));

	// Create a gun mesh component
	FP_Gun = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FP_Gun"));
	FP_Gun->SetOnlyOwnerSee(true);			// only the owning player will see this mesh
	FP_Gun->bCastDynamicShadow = false;
	FP_Gun->CastShadow = false;
	// FP_Gun->SetupAttachment(Mesh1P, TEXT("GripPoint"));
	FP_Gun->SetupAttachment(RootComponent);

	FP_MuzzleLocation = CreateDefaultSubobject<USceneComponent>(TEXT("MuzzleLocation"));
	FP_MuzzleLocation->SetupAttachment(FP_Gun);
	FP_MuzzleLocation->SetRelativeLocation(FVector(0.2f, 48.4f, -10.6f));

	// Default offset from the character location for projectiles to spawn
	GunOffset = FVector(100.0f, 0.0f, 10.0f);

	// Note: The ProjectileClass and the skeletal mesh/anim blueprints for Mesh1P, FP_Gun, and VR_Gun 
	// are set in the derived blueprint asset named MyCharacter to avoid direct content references in C++.

	// Create VR Controllers.
	R_MotionController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("R_MotionController"));
	R_MotionController->MotionSource = FXRMotionControllerBase::RightHandSourceId;
	R_MotionController->SetupAttachment(RootComponent);
	L_MotionController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("L_MotionController"));
	L_MotionController->SetupAttachment(RootComponent);

	// Create a gun and attach it to the right-hand VR controller.
	// Create a gun mesh component
	VR_Gun = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("VR_Gun"));
	VR_Gun->SetOnlyOwnerSee(true);			// only the owning player will see this mesh
	VR_Gun->bCastDynamicShadow = false;
	VR_Gun->CastShadow = false;
	VR_Gun->SetupAttachment(R_MotionController);
	VR_Gun->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));

	VR_MuzzleLocation = CreateDefaultSubobject<USceneComponent>(TEXT("VR_MuzzleLocation"));
	VR_MuzzleLocation->SetupAttachment(VR_Gun);
	VR_MuzzleLocation->SetRelativeLocation(FVector(0.000004, 53.999992, 10.000000));
	VR_MuzzleLocation->SetRelativeRotation(FRotator(0.0f, 90.0f, 0.0f));		// Counteract the rotation of the VR gun model.

	// Uncomment the following line to turn motion controllers on by default:
	//bUsingMotionControllers = true;

	MaxMinionActors = 5;
	InteractRange = 300.0f;
	SpawnOffset = FVector(0.0f, 0.0f, 30.0f);
}

void AGoMinionsCharacter::BeginPlay(){
	// Call the base class  
	Super::BeginPlay();

	//Attach gun mesh component to Skeleton, doing it here because the skeleton is not yet created in the constructor
	FP_Gun->AttachToComponent(Mesh1P, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("GripPoint"));

	// Show or hide the two versions of the gun based on whether or not we're using motion controllers.
	if (bUsingMotionControllers)
	{
		VR_Gun->SetHiddenInGame(false, true);
		Mesh1P->SetHiddenInGame(true, true);
	}else{
		VR_Gun->SetHiddenInGame(true, true);
		Mesh1P->SetHiddenInGame(false, true);
	}
}

void AGoMinionsCharacter::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	OnDetectMinion();
}

//////////////////////////////////////////////////////////////////////////
// Input

void AGoMinionsCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent){
	// set up gameplay key bindings
	check(PlayerInputComponent);

	// Bind jump events
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	// Bind fire event
	//PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &AGoMinionsCharacter::OnFire);

	// Enable touchscreen input
	EnableTouchscreenMovement(PlayerInputComponent);

	//PlayerInputComponent->BindAction("ResetVR", IE_Pressed, this, &AGoMinionsCharacter::OnResetVR);
	PlayerInputComponent->BindAction("Select", IE_Pressed, this, &AGoMinionsCharacter::OnSelect);
	PlayerInputComponent->BindAction("Spawn", IE_Pressed, this, &AGoMinionsCharacter::OnSpawn);

	// Bind movement events
	PlayerInputComponent->BindAxis("MoveForward", this, &AGoMinionsCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AGoMinionsCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AGoMinionsCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AGoMinionsCharacter::LookUpAtRate);
}

void AGoMinionsCharacter::OnFire(){

	

	/*if (CurrentMinion) {
		CurrentMinion->MoveMinion();
	}*/

	// try and fire a projectile
	//if ((ProjectileClass != NULL) && (Projectiles.Num() < MaxMinionActors)){
	//	AGoMinionsProjectile* goMinionsProjectile = nullptr;
	//	UWorld* const World = GetWorld();
	//	if (World != NULL){
	//		if (bUsingMotionControllers){
	//			const FRotator SpawnRotation = VR_MuzzleLocation->GetComponentRotation();
	//			const FVector SpawnLocation = VR_MuzzleLocation->GetComponentLocation();
	//			goMinionsProjectile = World->SpawnActor<AGoMinionsProjectile>(ProjectileClass, SpawnLocation, SpawnRotation);
	//		}else{
	//			const FRotator SpawnRotation = GetControlRotation();
	//			// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
	//			const FVector SpawnLocation = ((FP_MuzzleLocation != nullptr) ? FP_MuzzleLocation->GetComponentLocation() : GetActorLocation()) + SpawnRotation.RotateVector(GunOffset);

	//			//Set Spawn Collision Handling Override
	//			FActorSpawnParameters ActorSpawnParams;
	//			ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

	//			// spawn the projectile at the muzzle
	//			goMinionsProjectile = World->SpawnActor<AGoMinionsProjectile>(ProjectileClass, SpawnLocation, SpawnRotation, ActorSpawnParams);
	//		}
	//	}
	//	if (goMinionsProjectile) {
	//		Projectiles.Add(goMinionsProjectile);
	//	}
	//}

	//// try and play the sound if specified
	//if (FireSound != NULL)
	//{
	//	UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
	//}

	//// try and play a firing animation if specified
	//if (FireAnimation != NULL)
	//{
	//	// Get the animation object for the arms mesh
	//	UAnimInstance* AnimInstance = Mesh1P->GetAnimInstance();
	//	if (AnimInstance != NULL)
	//	{
	//		AnimInstance->Montage_Play(FireAnimation, 1.f);
	//	}
	//}
}

void AGoMinionsCharacter::OnResetVR(){
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

void AGoMinionsCharacter::BeginTouch(const ETouchIndex::Type FingerIndex, const FVector Location){
	if (TouchItem.bIsPressed == true){
		return;
	}if ((FingerIndex == TouchItem.FingerIndex) && (TouchItem.bMoved == false)){
		OnFire();
	}
	TouchItem.bIsPressed = true;
	TouchItem.FingerIndex = FingerIndex;
	TouchItem.Location = Location;
	TouchItem.bMoved = false;
}

void AGoMinionsCharacter::EndTouch(const ETouchIndex::Type FingerIndex, const FVector Location){
	if (TouchItem.bIsPressed == false){
		return;
	}
	TouchItem.bIsPressed = false;
}

void AGoMinionsCharacter::MoveForward(float Value){
	if (Value != 0.0f){
		// add movement in that direction
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void AGoMinionsCharacter::MoveRight(float Value){
	if (Value != 0.0f){
		// add movement in that direction
		AddMovementInput(GetActorRightVector(), Value);
	}
}

void AGoMinionsCharacter::TurnAtRate(float Rate){
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AGoMinionsCharacter::LookUpAtRate(float Rate){
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

bool AGoMinionsCharacter::EnableTouchscreenMovement(class UInputComponent* PlayerInputComponent){

	if (FPlatformMisc::SupportsTouchInput() || GetDefault<UInputSettings>()->bUseMouseForTouch){
		PlayerInputComponent->BindTouch(EInputEvent::IE_Pressed, this, &AGoMinionsCharacter::BeginTouch);
		PlayerInputComponent->BindTouch(EInputEvent::IE_Released, this, &AGoMinionsCharacter::EndTouch);

		return true;
	}
	
	return false;
}

void AGoMinionsCharacter::OnSelect(){
	AGoMinionPlayerController* goMinionPlayerController = Cast<AGoMinionPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (goMinionPlayerController) {
		if (CurrentMinion) {
			goMinionPlayerController->AddInteractWidgetMenuToViewport();
		}
		else {
			goMinionPlayerController->RemoveInteractWidgetMenuFromViewport();
		}
	}
}

void AGoMinionsCharacter::OnSpawn(){
	AFloor* Floor = Cast<AFloor>(RaycastItemsAndObjects());
	if (Floor) {
		if ((MinionClass != NULL) && (Minions.Num() < MaxMinionActors)){
			AMinion* Minion = nullptr;
			UWorld* const World = GetWorld();
			if (World != NULL){
				if (bUsingMotionControllers){
					Minion = World->SpawnActor<AMinion>(MinionClass, ImpactPoint, FRotator::ZeroRotator);
				}else{
					
					FActorSpawnParameters ActorSpawnParams;
					ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

					Minion = World->SpawnActor<AMinion>(MinionClass, ImpactPoint + SpawnOffset, FRotator::ZeroRotator); //ActorSpawnParams
				}
				if (Minion) {
					Minions.Add(Minion);
				}
			}
			
		}
	}
}

AActor* AGoMinionsCharacter::RaycastItemsAndObjects() {

	FVector Direction = FirstPersonCameraComponent->GetForwardVector();
	FVector Start = FirstPersonCameraComponent->GetComponentLocation();
	FVector End = Start + (Direction * InteractRange);
	FHitResult HitData(ForceInit);
	FCollisionQueryParams RV_TraceParams = FCollisionQueryParams(FName(TEXT("RV_Trace")), false, this);
	RV_TraceParams.AddIgnoredActor(this);
	RV_TraceParams.AddIgnoredActor(this);

	bool bIsHitSomething = GetWorld()->LineTraceSingleByObjectType(HitData, Start, End, FCollisionObjectQueryParams::AllObjects, RV_TraceParams);
	//DrawDebugLine(GetWorld(),Start,End,FColor(255, 0, 0),true, 2, 0, 1.0);

	if (bIsHitSomething) {

		if (HitData.GetActor() && !(HitData.GetActor() == this)) {
			AActor* HitTarget = HitData.GetActor();
			ImpactPoint = HitData.ImpactPoint;
			return HitTarget;
		}
	}
	return nullptr;
}

void AGoMinionsCharacter::OnDetectMinion(){
	
	CurrentMinion = Cast<AMinion>(RaycastItemsAndObjects());
	if (CurrentMinion) {
		AGoMinionPlayerController* goMinionPlayerController = Cast<AGoMinionPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
		if (goMinionPlayerController) {
			goMinionPlayerController->AddInteractWidgetToViewport();
		}
	}
	else {
		AGoMinionPlayerController* goMinionPlayerController = Cast<AGoMinionPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
		if (goMinionPlayerController) {
			goMinionPlayerController->RemoveInteractWidgetFromViewport();
		}
	}
}
