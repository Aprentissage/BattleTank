// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMouvementComponent.generated.h"

class UTankTrack;

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankMouvementComponent : public UNavMovementComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Input")
	void IntendMoveForward(float Throw);

	UFUNCTION(BlueprintCallable, Category = "Input")
	void IntendTurnRight(float Throw);

	UFUNCTION(BlueprintCallable, Category = "Input")
	void initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet);



private:
	// called from the pathfinding logic by the AIcontrolers
	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;
	UTankTrack* LeftTrack = nullptr;
	UTankTrack* RightTrack = nullptr;



};
