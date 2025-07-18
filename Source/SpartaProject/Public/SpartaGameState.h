#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "SpartaGameState.generated.h"


UCLASS()
class SPARTAPROJECT_API ASpartaGameState : public AGameState
{
	GENERATED_BODY()

public:
	ASpartaGameState();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Score")
	int32 Score;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	int32 SpawnedCoinCount;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	int32 CollectedCoinCount;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float LevelDuration;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float WaveDuration;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	int32 CurrentLevelIndex;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Level")
	TArray<FName> LevelMapNames;
	int32 MaxLevel;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	int32 CurrentWaveIndex;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	int32 MaxWave;
	UFUNCTION(BlueprintPure)
	int32 GetScore() const;
	UFUNCTION(BlueprintCallable)
	void AddScore(int32 Amount);
	UFUNCTION(BlueprintCallable)
	void OnGameOver();
	
	
	FTimerHandle HUDUpdateTimerHandle;
	void OnCoinCollected();
	void UpdateHUD();
	virtual void BeginPlay() override;
	void StartLevel();
	void OnLevelTimeUp();
	void OnWaveTimerUp();
	void EndLevel();
	void StartWave();
	void EndWave();
	FTimerHandle LevelTimerHandle;
	FTimerHandle WaveTimerHandle;
	
};
