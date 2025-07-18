// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "ItemSpawnRow.h"
#include "SpawnVolume.generated.h"

UCLASS()
class SPARTAPROJECT_API ASpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnVolume();

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "SpawnVolume|Component")
	USceneComponent* Scene;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "SpawnVolume|Component")
	UBoxComponent* SpawningBox;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UDataTable*> ItemDataTables;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "SpawnVolume|Component")
	int ItemIndex;
	UFUNCTION(BlueprintCallable)
	AActor* SpawnRandomItem();

	FItemSpawnRow* GetRandomItem() const;
	FVector GetRandomPointInVolume() const;
	AActor* SpawnItem(TSubclassOf<AActor> ItemClass);
};
