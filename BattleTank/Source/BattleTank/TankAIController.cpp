// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "TankAimingComponent.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto AITank = GetPawn();

	if (!ensure(PlayerTank && AITank)) { return; }

	// Move towards player
	MoveToActor(PlayerTank, AcceptanceRadius); // TODO check radius is in cm

	// Aim towards the player
	auto AimingComponent = AITank->FindComponentByClass<UTankAimingComponent>();
	AimingComponent->AimAt(PlayerTank->GetActorLocation());

	// Fire at player if ready
	AimingComponent->Fire(); // TODO Limit firing rate
}
