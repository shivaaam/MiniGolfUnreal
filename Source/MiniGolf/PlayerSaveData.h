// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "PlayerSaveData.generated.h"

/**
 * 
 */


USTRUCT(BlueprintType)
struct FSaveDataAttributes
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
		int maxLevelsClearedIndex;
	UPROPERTY(EditAnywhere)
		TArray<int> skillLevels;

	UPROPERTY(EditAnywhere)
		int coinsCollected;
};


UCLASS()
class MINIGOLF_API UPlayerSaveData : public USaveGame
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Exec)
		void SavePlayerState(FSaveDataAttributes attribs);

	UFUNCTION(BlueprintCallable, Exec)
		void LoadPlayerState(FSaveDataAttributes attribs);
	
	UPROPERTY(EditAnywhere)
		FSaveDataAttributes saveAttibutes;
};
