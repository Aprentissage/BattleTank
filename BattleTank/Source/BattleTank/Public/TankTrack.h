// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * TankTrack is used to set max driving force and to aply forces to the tank
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetThrottle(float Throttle);

	// Max Force per Track
	UPROPERTY(EditDefaultsOnly)
	float TrackMaxDringForce = 40000000; // Assume 40 tonnes, and 1g accélération

private:
	UTankTrack();
	virtual void BeginPlay() override;	
	TArray<class ASprungWheel*> GetWheels() const;

	//UFUNCTION()
	//void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	void DriveTrack(float CurrentThrottle);
	
};


