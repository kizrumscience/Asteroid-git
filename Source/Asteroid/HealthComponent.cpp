// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"
//#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent():
	Health(100) {	
}

void UHealthComponent::OnOwnerDamaged(AActor* DamagedActor, float Damage,
	const UDamageType* DamageType, AController* inst, AActor* DamageCauser) {
	ChangeHealth(Damage);
}

// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::OnOwnerDamaged);
}

void UHealthComponent::ChangeHealth(float value) {
	Health -= value;
	if (Health <= 0) {
		GetOwner()->OnTakeAnyDamage.RemoveDynamic(this, &UHealthComponent::OnOwnerDamaged); // отвязка диспатчера

		GetOwner()->Destroy();
	}
}

float UHealthComponent::GetHealth() const {
	return Health;
}


