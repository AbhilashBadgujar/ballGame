// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/BoxComponent.h"
#include "HerpController.generated.h"

UCLASS()
class BALLGAME_API AHerpController : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AHerpController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UFUNCTION()
	void OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(EditAnywhere)
		float Speed = 10.0f;

	UPROPERTY(EditAnywhere)
		UBoxComponent* CollisonBox;

	
	FVector currentVelocity;

	void MoveHorizontaly(float AxixsValue);
	void MoveVertically(float AxixsValue);
	void OnRestart();
	
};
