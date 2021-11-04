// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/SphereComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ShootProjectile.generated.h"

UCLASS()
class ASTEROID_API AShootProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AShootProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnProjectileOverlap(UPrimitiveComponent* OpelappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 BodyIndex,
		bool Sweep, const FHitResult& Hit
	);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Shooting")
	USphereComponent* Collision;

	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Shooting")
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "Shooting")
	float ProjectileSpeed;

	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "Shooting")
	float Damage;
};
