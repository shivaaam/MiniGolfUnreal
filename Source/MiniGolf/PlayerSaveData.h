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
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FLinearColor ballColor;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int maxLevelsClearedIndex;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray<int> skillLevels;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int coinsCollected;

	FSaveDataAttributes()
	{
		maxLevelsClearedIndex = -1;
	}
};


UCLASS()
class MINIGOLF_API UPlayerSaveData : public USaveGame
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Exec)
		void SavePlayerState(UPlayerSaveData* saveInstance, FSaveDataAttributes attribs, int slot);

	UFUNCTION(BlueprintCallable, Exec)
		FSaveDataAttributes LoadPlayerState(UPlayerSaveData* saveInstance, int slot);
	
	UPROPERTY(EditAnywhere)
		FSaveDataAttributes saveAttibutes;
};
