// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameFramework/GameModeBase.h"
#include "CoinGameMode.generated.h"

/**
 * 
 */
UCLASS()
class BALLGAME_API ACoinGameMode : public AGameModeBase
{
	GENERATED_BODY()
public:
		virtual void BeginPlay() override;

		virtual void Tick(float DeltaTime) override;

		int CoinToCollect;

		UFUNCTION(BlueprintCallable, Category = "UMG Game")
			void ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass);

		void OnCoinCollected();

protected: 
		
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UMG Game")
		TSubclassOf<UUserWidget> StartingWidgitClass;

	UPROPERTY()
		UUserWidget* CurrentWidget;
	
	
};
