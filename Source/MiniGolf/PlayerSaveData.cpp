// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerSaveData.h"

void UPlayerSaveData::SavePlayerState(FSaveDataAttributes attribs)
{
	UE_LOG(LogTemp, Warning, TEXT("player data saved"));
}

void UPlayerSaveData::LoadPlayerState(FSaveDataAttributes attribs)
{
	UE_LOG(LogTemp, Warning, TEXT("player data loaded"));
}