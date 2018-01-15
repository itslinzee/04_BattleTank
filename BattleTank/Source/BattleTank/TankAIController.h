// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

// Forward declaration
class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	virtual void Tick(float DeltaSeconds) override;

private:
	ATank* AITank = nullptr;

	ATank* PlayerTank = nullptr;

	// How close can the AI tank get to the player
	//UPROPERTY(BlueprintDefautsOnly)
		float AcceptanceRadius = 3000; // TODO find sensible default (Assume in cm)
};
