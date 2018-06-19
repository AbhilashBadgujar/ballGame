// Fill out your copyright notice in the Description page of Project Settings.


#include "HerpController.h"
#include "Components/InputComponent.h"
#include "GameFramework/Actor.h"
#include "CoinController.h"
#include "CoinGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "ballGame.h"



// Sets default values
AHerpController::AHerpController()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	CollisonBox = CreateAbstractDefaultSubobject<UBoxComponent>(TEXT("Root"));
	CollisonBox->bGenerateOverlapEvents = true;
	CollisonBox->OnComponentBeginOverlap.AddDynamic(this, &AHerpController::OnOverlap);

	
}

// Called when the game starts or when spawned
void AHerpController::BeginPlay()
{
	
	Super::BeginPlay();
	
}

// Called every frame
void AHerpController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!currentVelocity.IsZero())
	{
		FVector NewLocation = GetActorLocation() + (Speed * currentVelocity * DeltaTime);
		SetActorLocation(NewLocation);
		
	}

}

// Called to bind functionality to input
void AHerpController::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	/*PlayerInputComponent->BindAxis("MoveX", this, &AHerpController::MoveHorizontaly);*/

	PlayerInputComponent->BindAxis("MoveX", this, &AHerpController::MoveHorizontaly);
	PlayerInputComponent->BindAxis("MoveY", this, &AHerpController::MoveVertically);
	PlayerInputComponent->BindAction("Restart", IE_Pressed, this, &AHerpController::OnRestart).bExecuteWhenPaused = true;
}

void AHerpController::OnOverlap (UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->IsA(ACoinController::StaticClass()))
	{
		OtherActor->Destroy();
		((ACoinGameMode*)GetWorld()->GetAuthGameMode())->OnCoinCollected();
	}
	

}




void AHerpController::MoveHorizontaly(float AxisValue) {

	currentVelocity.X = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 100.0f;
}

void AHerpController::MoveVertically(float AxisValue) {

	currentVelocity.Y = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 100.0f;
}

void AHerpController::OnRestart(){

	UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
}

