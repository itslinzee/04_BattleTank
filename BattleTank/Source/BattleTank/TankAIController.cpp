// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "Tank.h"

void ATankAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (PlayerTank)
	{
		AITank = Cast<ATank>(GetPawn());
		if (!AITank) { return; }

		// Move towards player
		MoveToActor(PlayerTank, AcceptanceRadius);

		// Aim towards the player
		AITank->AimAt(PlayerTank->GetActorLocation());

		// Fire at player if ready
		AITank->Fire(); // TODO AI fires every frame
	}
}
