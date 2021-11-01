// Fill out your copyright notice in the Description page of Project Settings.

#include "PalyerPawn.h"

// Sets default values
APalyerPawn::APalyerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bUseControllerRotationPitch = true;
	bUseControllerRotationYaw = true;

	PawnCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("PawnCollision"));
	SetRootComponent(PawnCollision);

	PawnMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PawnMesh"));
	PawnMesh->SetupAttachment(RootComponent);

	CamSpringArm = CreateAbstractDefaultSubobject<USpringArmComponent>(TEXT("CamSpringArm"));
	CamSpringArm->SetupAttachment(RootComponent);

	PawnCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PawnCamera"));
	PawnCamera->SetupAttachment(CamSpringArm);

	PawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>("PawnMovement");
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

void APalyerPawn::MoveForwardBack(float Axis){
	UE_LOG(LogTemp, Warning, TEXT("Move Forward: %f"), Axis);
	AddMovementInput(GetActorForwardVector(), Axis, false);
}

void APalyerPawn::MoveRightLeft(float Axis){
	UE_LOG(LogTemp, Warning, TEXT("Move Right: %f"), Axis);
	AddMovementInput(GetActorRightVector(), Axis, false);
}

void APalyerPawn::LookForwardBack(float Axis){
	AddControllerYawInput(-Axis);
}

void APalyerPawn::LookRightLeft(float Axis) {
	AddControllerPitchInput(Axis);
}

// Called to bind functionality to input
void APalyerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//PlayerInputComponent->BindTouch(EInputEvent::IE_Pressed, this, &APlayerPawn::OnTouch)

	PlayerInputComponent->BindAxis("MoveForward/Back", this, &APalyerPawn::MoveForwardBack);
	PlayerInputComponent->BindAxis("MoveRight/Left", this, &APalyerPawn::MoveRightLeft);
	PlayerInputComponent->BindAxis("LookForward/Back", this, &APalyerPawn::LookForwardBack);
	PlayerInputComponent->BindAxis("LookRight/Left", this, &APalyerPawn::LookRightLeft);

}



