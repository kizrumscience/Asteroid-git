// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "GameAttempt.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAttemptsEndedEvent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAttemptsChangedEvent, int, ChangeValue);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ASTEROID_API UGameAttempt : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGameAttempt();

	UFUNCTION(BlueprintCallable, Category = "Game Attempts")
	void ChangeAttempts(int value);

	UFUNCTION(BlueprintPure, Category = "Game Attempts")
	int GetAttempts();

	UPROPERTY(BlueprintAssignable, Category = "Game Attempts")
	FAttemptsEndedEvent AttemptsEnded;

	UPROPERTY(BlueprintAssignable, Category = "Game Attempts")
	FAttemptsChangedEvent AttemptsChanged;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Game Attempts")
	int Attempts;

	UFUNCTION()
	void OnPlayerDamaged(AActor* DamagedActor, float Damage,
			const UDamageType* DamageType, AController* inst, AActor* DamageCauser);
};
