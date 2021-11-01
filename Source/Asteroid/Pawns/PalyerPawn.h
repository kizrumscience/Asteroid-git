// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Pawn.h"

#include "PalyerPawn.generated.h"

UCLASS()
class ASTEROID_API APalyerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APalyerPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//void OnTouch(ETouchIndex::Type FingerIndex, FVector TouchLocation);

	void MoveForwardBack(float Axis);
	void MoveRightLeft(float Axis);
	void LookForwardBack(float Axis);
	void LookRightLeft(float Axis);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category="Pawn")
	UStaticMeshComponent* PawnMesh;

	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Pawn")
	UBoxComponent* PawnCollision;

	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Pawn")
	USpringArmComponent* CamSpringArm;
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Pawn")
	UCameraComponent* PawnCamera;

	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Controls")
	UFloatingPawnMovement* PawnMovement;
};
