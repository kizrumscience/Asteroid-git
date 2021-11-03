// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemySpawnController.h"

// Called when the game starts
void UEnemySpawnController::BeginPlay()
{
	Super::BeginPlay();

	/*SpawnStage = FEnemySpawnInfo();
	SpawnStage.NumOfEnemis = 10;
	SpawnStage.SpawnDelay = 1.f;*/

	Random.GenerateNewSeed(); // create new zerno

	StartSpawnStage();
}

void UEnemySpawnController::SpawnEnemy(){
	FActorSpawnParameters SpawnParameters;
	GetWorld()->SpawnActor<AEnemyPawn>(SpawnStage.EnemyClass, SpawnStage.SpawnTransform, SpawnParameters);

	++EnemiesSpawned;

	if (EnemiesSpawned < SpawnStage.NumOfEnemis) {
		GetWorld()->GetTimerManager().SetTimer(EnemySpawnTimer, this,
			&UEnemySpawnController::SpawnEnemy, SpawnStage.SpawnDelay, false
		);
	}
}

 void UEnemySpawnController::StartSpawnStage(){

	 SpawnStage = SpawnStages[Random.RandRange(0, SpawnStages.Num() - 1)];
	 EnemiesSpawned = 0;
	 SpawnEnemy();

	 GetWorld()->GetTimerManager().SetTimer(ChangeStageTimer, this,
		 &UEnemySpawnController::StartSpawnStage, 
		 Random.RandRange(StageMinDelay, StageMaxDelay), false
	 );
}


