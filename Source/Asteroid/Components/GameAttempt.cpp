// Fill out your copyright notice in the Description page of Project Settings.


#include "GameAttempt.h"
#include "GameAttempt.h"

// Sets default values for this component's properties
UGameAttempt::UGameAttempt():
	Attempts(3) 
{
}

void UGameAttempt::ChangeAttempts(int value)
{
	Attempts -= value;
	AttemptsChanged.Broadcast(value);
	if (Attempts <= 0) {
		AttemptsEnded.Broadcast();
	}
}

int UGameAttempt::GetHealths() const
{
	return 0;
}

// Called when the game starts
void UGameAttempt::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

