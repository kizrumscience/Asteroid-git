// Copyright Epic Games, Inc. All Rights Reserved.


#include "AsteroidGameModeBase.h"

AAsteroidGameModeBase::AAsteroidGameModeBase() {
	EnemySpawnController = CreateDefaultSubobject<UEnemySpawnController>(TEXT("EnemySpawnController"));
	GameAttempt = CreateDefaultSubobject<UGameAttempt>(TEXT("GameAttemp"));
}