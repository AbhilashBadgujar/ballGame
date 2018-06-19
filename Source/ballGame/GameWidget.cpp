// Fill out your copyright notice in the Description page of Project Settings.


#include "GameWidget.h"


void UGameWidget::Load() {

	const FName TextBlockName = FName(TEXT("ScoreTextBlock"));

	if (ScoreText == nullptr)
	{
		ScoreText = (UTextBlock*)(WidgetTree->FindWidget(TextBlockName));
	}
}

void UGameWidget::OnGameOverLoad() {
	if (ScoreText != nullptr) {
		ScoreText->SetText(FText::FromString(TEXT("You Win!\n Press R to Restart the game.")));
	}

}
