// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "AIController.h"
#include "TankIAController.generated.h"

//Forward declerations
class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankIAController : public AAIController
{
	GENERATED_BODY()
	
public:	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:

	float AcceptanceRadius = 3000;
};
