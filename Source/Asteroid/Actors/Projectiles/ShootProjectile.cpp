// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootProjectile.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/DamageType.h"
#include "GameFramework/Pawn.h"

#include "Components/StaticMeshComponent.h"

// Sets default values
AShootProjectile::AShootProjectile():
	ProjectileSpeed(200)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Collision = CreateDefaultSubobject<USphereComponent>(TEXT("ProjectileCollision"));
	RootComponent = Collision;
	Collision->SetCollisionObjectType(ECC_WorldDynamic);
	Collision->SetCollisionResponseToAllChannels(ECR_Ignore);
	Collision->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMesh"));
	Mesh->SetupAttachment(RootComponent);
	Mesh->SetCollisionProfileName("NoCollision");
}

void AShootProjectile::OnProjectileOverlap(
	UPrimitiveComponent* OpelappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32_t BodyIndex,
	bool Sweep, const FHitResult& Hit) {
	if (!GetOwner()) {
		return;
	}
	APawn* PawnOwner = Cast<APawn>(GetOwner());
	if (!PawnOwner) {
		return;
	}

	UGameplayStatics::ApplyDamage(OtherActor, Damage, PawnOwner->GetController(), this, UDamageType::StaticClass());

	Destroy();
}

// Called when the game starts or when spawned
void AShootProjectile::BeginPlay()
{
	Super::BeginPlay();
	if (GetOwner()) {
		UE_LOG(LogTemp, Log, TEXT("Owner"))
		// ignor interaction with owner
		Collision->IgnoreActorWhenMoving(GetOwner(), true);
	}
	// dispatcher overlap
	Collision->OnComponentBeginOverlap.AddDynamic(this, &AShootProjectile::OnProjectileOverlap);
}

// Called every frame
void AShootProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalOffset(FVector(ProjectileSpeed * DeltaTime, 0.f, 0.f)); // ProjectileSpeed * DeltaTime for independent paint on framespeed

}

