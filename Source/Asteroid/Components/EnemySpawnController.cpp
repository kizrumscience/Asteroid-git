// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemySpawnController.h"

// Called when the game starts
void UEnemySpawnController::BeginPlay()
{
	Super::BeginPlay();

	SpawnStage = FEnemySpawnInfo();
	SpawnStage.NumOfEnemis = 10;
	SpawnStage.SpawnDelay = 1.f;

	StartSpawnStage();
}

void UEnemySpawnController::SpawnEnemy(){
	FActorSpawnParameters SpawnParameters;
	GetWorld()->SpawnActor<APawn>(SpawnStage.EnemyClass, SpawnStage.SpawnTransform, SpawnParameters);
	++EnemiesSpawned;

	if (EnemiesSpawned >= SpawnStage.NumOfEnemis) {
		GetWorld()->GetTimerManager().ClearTimer(EnemySpawnTimer);
	}
}

 void UEnemySpawnController::StartSpawnStage(){
	 GetWorld()->GetTimerManager().SetTimer(EnemySpawnTimer, this, 
		 &UEnemySpawnController::SpawnEnemy, SpawnStage.SpawnDelay, true);
}


