// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../EnemyPawn.h"

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/World.h"
#include "TimerManager.h"

#include "EnemySpawnController.generated.h"

USTRUCT(BlueprintType)
struct FEnemySpawnInfo {
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Shooting")
	TSubclassOf<AEnemyPawn> EnemyClass = AEnemyPawn::StaticClass();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shooting")
	FTransform SpawnTransform;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Shooting")
	int NumOfEnemis;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Shooting")
	float SpawnDelay;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ASTEROID_API UEnemySpawnController : public UActorComponent
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enemies")
	TArray<FEnemySpawnInfo> SpawnStages;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enemies")
	float StageMinDelay;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enemies")
	float StageMaxDelay;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	// spawn pawns
	void SpawnEnemy(); 

	// stage of spawn massive pawns
	void StartSpawnStage(); 

	// count of spawned bot for stop timer
	int EnemiesSpawned;

	FTimerHandle ChangeStageTimer;
	FTimerHandle EnemySpawnTimer;
	FRandomStream Random; // struct for random
	FEnemySpawnInfo SpawnStage;
};
