// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerSaveData.h"
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>

void UPlayerSaveData::SavePlayerState(UPlayerSaveData* saveInstance, FSaveDataAttributes attribs, int slot)
{
	saveInstance->saveAttibutes.coinsCollected = attribs.coinsCollected;
	saveInstance->saveAttibutes.maxLevelsClearedIndex = attribs.maxLevelsClearedIndex;
	saveInstance->saveAttibutes.ballColor = attribs.ballColor;

	// do something for the array

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