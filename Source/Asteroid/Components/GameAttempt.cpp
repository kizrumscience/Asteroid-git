// Fill out your copyright notice in the Description page of Project Settings.


#include "GameAttempt.h"
#include "GameAttempt.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Pawn.h"

// Sets default values for this component's properties
UGameAttempt::UGameAttempt():
	Attempts(3) 
{
}

// Called when the game starts
void UGameAttempt::BeginPlay()
{
	Super::BeginPlay();

	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0);

	/*if (!PlayerPawn) {
		UE_LOG(LogTemp, Error, TEXT("No play"))
	}*/

	PlayerPawn->OnTakeAnyDamage.AddDynamic(this, &UGameAttempt::OnPlayerDamaged);
}

void UGameAttempt::OnPlayerDamaged(AActor* DamagedActor, float Damage,
	const UDamageType* DamageType, AController* inst, AActor* DamageCauser) {
	ChangeAttempts(1);
}

void UGameAttempt::ChangeAttempts(int value)
{
	Attempts -= value;
	AttemptsChanged.Broadcast(value);
	if (Attempts <= 0) {
		AttemptsEnded.Broadcast();
	}

	UE_LOG(LogTemp, Log, TEXT("Attempts:%i"), Attempts);
}

int UGameAttempt::GetAttempts() const
{
	return Attempts;
}
