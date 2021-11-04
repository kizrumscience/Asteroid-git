// Fill out your copyright notice in the Description page of Project Settings.


#include "../Components/ConditionComponent.h"

// Sets default values
AConditionComponent::AConditionComponent() :
	Health(100) {
}

// Called when the game starts or when spawned
void AConditionComponent::BeginPlay()
{
	Super::BeginPlay();

	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &AConditionComponent::OnOwnerDamaged);
	
}

void AConditionComponent::OnOwnerDamaged(AActor* DamagedActor, float Damage,
	const UDamageType* DamageType, AController* inst, AActor* DamageCauser){
	ChangeHealth(Damage);
}

void AConditionComponent::ChangeHealth(float value) {
	Health -= value;
	if (Health <= 0) {
		GetOwner()->OnTakeAnyDamage.RemoveDynamic(this, &AConditionComponent::OnOwnerDamaged); // отвязка диспатчера

		GetOwner()->Destroy();
	}
}

float AConditionComponent::GetHealth() const{
	return Health;
}


