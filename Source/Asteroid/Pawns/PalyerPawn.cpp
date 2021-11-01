// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawns/PalyerPawn.h"

// Sets default values
APalyerPawn::APalyerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APalyerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APalyerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APalyerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

