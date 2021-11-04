// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ASTEROID_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

	UFUNCTION(BlueprintCallable, Category = "Condition")
		void ChangeHealth(float value);

	UFUNCTION(BlueprintCallable, Category = "Condition")
		float GetHealth();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Health")
	float Health;

	UFUNCTION()
		void OnOwnerDamaged(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* inst, AActor* DamageCauser);
};
