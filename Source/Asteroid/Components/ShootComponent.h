// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../Actors/Projectiles/ShootProjectile.h"

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ShootComponent.generated.h"

USTRUCT(BlueprintType)
struct FShootInfo {
	GENERATED_BODY()
public:

	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "Shooting")
	TSubclassOf<AShootProjectile> ProjectileClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shooting")
	FVector Offset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shooting")
	float Angle;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ASTEROID_API UShootComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UShootComponent();

	UFUNCTION(BlueprintCallable, Category = "Shooting")
	void StartShooting();
	void StopShooting();

	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "Shooting")
	float ShootPeriod;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shooting")
	TArray<FShootInfo> ShootInfos;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void Shoot();

	FTimerHandle ShootingTimer;
};
