 // Fill out your copyright notice in the Description page of Project Settings.

#include "CoinGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "GameWidget.h"




void ACoinGameMode::BeginPlay() {
	Super::BeginPlay();
	CoinToCollect = 10;

	ChangeMenuWidget(StartingWidgitClass);
	((UGameWidget*)CurrentWidget)->Load();
}

void ACoinGameMode::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

void ACoinGameMode::ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass)
{
	if (CurrentWidget != nullptr)
	{
		CurrentWidget->RemoveFromViewport();
		CurrentWidget = nullptr;
	}

	if (NewWidgetClass != nullptr)
	{
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), NewWidgetClass);
		if (CurrentWidget != nullptr)
		{
			CurrentWidget->AddToViewport();
		}
	}
}

void ACoinGameMode::OnCoinCollected()
{
	CoinToCollect--;

	if (CoinToCollect == 0)
	{
		((UGameWidget*)CurrentWidget)->OnGameOverLoad();
		UGameplayStatics::SetGamePaused(GetWorld(), true);
	}
	
}



