// Fill out your copyright notice in the Description page of Project Settings.


#include "Container.h"
#include "Components/BoxComponent.h"
#include "Minion.h"
#include "Components/TextRenderComponent.h"
#include "GoMinionsCharacter.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AContainer::AContainer(){
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshVisual"));
	RootComponent = StaticMeshVisual;

	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger"));
	Trigger->SetupAttachment(StaticMeshVisual);

	Text = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Text"));
	Text->SetupAttachment(StaticMeshVisual);

	bIsTriggered = false;
}

// Called when the game starts or when spawned
void AContainer::BeginPlay(){
	Super::BeginPlay();
	FString EnumString = UEnum::GetValueAsString<ENeededObjectEnum>(NeededObjectEnum);
	Text->SetText(EnumString);
	Trigger->OnComponentBeginOverlap.AddDynamic(this, &AContainer::OnBoxBeginOverlap);
	Trigger->OnComponentEndOverlap.AddDynamic(this, &AContainer::OnBoxEndOverlap);
	goMinionsCharacter = Cast<AGoMinionsCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
}

// Called every frame
void AContainer::Tick(float DeltaTime){
	Super::Tick(DeltaTime);
	
	if (goMinionsCharacter) {
		FVector actorLoc = this->GetActorLocation();
		FVector playerLoc = goMinionsCharacter->GetActorLocation();
		FRotator PlayerRot = FRotationMatrix::MakeFromX(playerLoc - actorLoc).Rotator();
		PlayerRot.Pitch = 0;
		SetActorLocation(actorLoc); 
		SetActorRotation(PlayerRot);
	}
}

void AContainer::OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult){
	if (OtherActor && (OtherActor != this)) {
		AMinion* Minion = Cast<AMinion>(OtherActor);
		if (Minion && !bIsTriggered) {
			bIsTriggered = true;
			Minion->SetMinionSelection(false);
			LogInformation(Minion);
		}
	}
}

void AContainer::OnBoxEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex){
	if (OtherActor && (OtherActor != this)) {
		AMinion* Minion = Cast<AMinion>(OtherActor);
		if (Minion && bIsTriggered) {
			bIsTriggered = false;
		}
	}
}

void AContainer::LogInformation(AMinion* Minion){
	FString MinionName = Minion->GetFName().ToString();
	FString EnumString = UEnum::GetValueAsString<ENeededObjectEnum>(Minion->GetNeededObjectEnum());

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString::Printf(TEXT("Minion %s has delivered %s"), *MinionName, *EnumString));
	UE_LOG(LogTemp, Warning, TEXT("Minion %s has delivered %s"), *MinionName, *EnumString);
}

