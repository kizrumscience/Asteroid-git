// Fill out your copyright notice in the Description page of Project Settings.

#include "ShootComponent.h"
#include "Engine/World.h"
#include "TimerManager.h"

// Sets default values for this component's properties
UShootComponent::UShootComponent():
	ShootPeriod(1.f){

}

void UShootComponent::Shoot() {
	UE_LOG(LogTemp, Log, TEXT("Shoot"))

	FActorSpawnParameters SpawnParameters;

	FVector SpawnLocation = GetOwner()->GetActorLocation();
	FRotator SpawnRotation = GetOwner()->GetActorRotation();

	GetWorld()->SpawnActor<AShootProjectile>(ProjectileClass, SpawnLocation, SpawnRotation, SpawnParameters);
}

void UShootComponent::StartShooting() {
	GetWorld()->GetTimerManager().SetTimer(ShootingTimer, this, &UShootComponent::Shoot, ShootPeriod, true, 0.f);
}

void UShootComponent::StopShooting() {
	GetWorld()->GetTimerManager().ClearTimer(ShootingTimer);
}

// Called when the game starts
void UShootComponent::BeginPlay(){
	Super::BeginPlay();

	StartShooting();
	// ...
	
}


