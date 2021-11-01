// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootComponent.h"
#include "Engine/World.h"
#include "TimerManager.h"

// Sets default values for this component's properties
UShootComponent::UShootComponent(){

}

void UShootComponent::Shoot() {

}

void UShootComponent::StartShooting() {
	GetWorld()->GetTimerManager().SetTimer(ShootingTimer, this, 
		&UShootComponent::Shoot, true, ShootPeriod);
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


