// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "ConditionComponent.generated.h"

UCLASS()
class ASTEROID_API AConditionComponent : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AConditionComponent();

	UFUNCTION(BlueprintCallable, Category = "Condition")
	void ChangeHealth(float value);

	UFUNCTION(BlueprintCallable, Category = "Condition")
	float GetHealth() const;

	UFUNCTION()
	void OnOwnerDamaged(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* inst, AActor* DamageCauser);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Health")
	float Health;

	
	// DamagedActor - who give damage
	//Instigator - тот уто ответственнен за урон
	//DamageCauser - who create damage
};
