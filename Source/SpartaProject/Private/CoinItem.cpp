// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine/World.h"
#include "SpartaGameState.h"
#include "CoinItem.h"

ACoinItem::ACoinItem()
{
	PointValue =0;
	ItemType = "DefaultCoin";
}

void ACoinItem::ActivateItem(AActor* Activator)
{
	Super::ActivateItem(Activator);
	if (Activator &&   Activator->ActorHasTag("Player"))
	{
		if (UWorld* World = GetWorld())
		{
			if (ASpartaGameState* GameState = World->GetGameState<ASpartaGameState>())
			{
				GameState->AddScore(PointValue);
				GameState->OnCoinCollected();
			}
		}
		DestroyItem();
	}
}
