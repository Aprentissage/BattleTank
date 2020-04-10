// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class BATTLETANK_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	//-1 is max downward speed, and +1 is max up mouvement
	void Rotate(float RelativeSpeed);

private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecond = 5; // Sensible default

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxAzimuthDegrees = 40; // Sensible default

	UPROPERTY(EditAnywhere, Category = Setup)
	float MinAzimuthDegrees = 0; // Sensible default
	
};