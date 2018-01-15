// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = Input)
		void SetThrottle(float Throttle);
	
private:
	// Max force per track, in Newtons
	UPROPERTY(EditDefaultsOnly, Category = Throttle)
		float TrackMaxDrivingForce = 40000000; // Assume 40 ton tank, 1g acceleration
};
