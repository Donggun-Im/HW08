// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseItem.h"
#include "SpeedUpItem.generated.h"

/**
 * 
 */
UCLASS()
class SPARTAPROJECT_API ASpeedUpItem : public ABaseItem
{
	GENERATED_BODY()
	void BeginPlay() override;
	
	ASpeedUpItem();
	UFUNCTION()
	void ActivateItem(AActor* Activator);
	UFUNCTION()
	void SpeedUp();
	UFUNCTION()
	void SpeedDown();
	FTimerHandle TimerHandle;
};
