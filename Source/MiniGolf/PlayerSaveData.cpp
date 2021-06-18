// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerSaveData.h"
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>

void UPlayerSaveData::SavePlayerState(UPlayerSaveData* saveInstance, FSaveDataAttributes attribs, int slot)
{
	saveInstance->saveAttibutes.coinsCollected = attribs.coinsCollected;
	saveInstance->saveAttibutes.maxLevelsClearedIndex = attribs.maxLevelsClearedIndex;
	saveInstance->saveAttibutes.ballColor = attribs.ballColor;

	saveInstance->saveAttibutes.skillLevels = TArray<int>{ attribs.skillLevels[0], attribs.skillLevels[1], attribs.skillLevels[2] };

	UGameplayStatics::SaveGameToSlot(saveInstance, TEXT("PlayerSaveData_Slot0"), slot);
}

FSaveDataAttributes UPlayerSaveData::LoadPlayerState(UPlayerSaveData* saveInstance, int slot)
{
	if (UGameplayStatics::DoesSaveGameExist(TEXT("PlayerSaveData_Slot0"), slot))
	{
		saveInstance = Cast<UPlayerSaveData>(UGameplayStatics::LoadGameFromSlot(TEXT("PlayerSaveData_Slot0"), slot));
	}

	return saveInstance->saveAttibutes;
}