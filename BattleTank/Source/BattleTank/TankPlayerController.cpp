// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto PossessedTank = GetControlledTank();
	if (!PossessedTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller not possessing a tank."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller possessing tank %s"), *(PossessedTank->GetName()));
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }
	
	FVector HitLocation; // Out parameter
	if (GetSightRayHitLocation(HitLocation)) // Has side-effect, is going to line tace
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit Location: %s"), *HitLocation.ToString());
		// TODO Tell controlled tank to aim at this point
	}

}

// Get world location of linetrace through crosshair, true if it hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	// Line trace through crosshair and determine if it hit something
		// If it hit something
			// Set out hit location as location of the something hit and return true
		// If it did not hit something
			// Set out hit location to 0, 0, 0 and return false
	OutHitLocation = FVector(1.0f);
	return true;
}
