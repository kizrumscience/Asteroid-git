// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Components/EnemySpawnController.h"

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#include "AsteroidGameModeBase.generated.h"


UCLASS()
class ASTEROID_API AAsteroidGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	AAsteroidGameModeBase();

	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Enemies")
	UEnemySpawnController* EnemySpawnController;
};
