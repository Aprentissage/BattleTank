// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "Tank.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankIAController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankIAController : public AAIController
{
	GENERATED_BODY()
	
public:	
	virtual void BeginPlay() override;

private:
	ATank* GetControlledTank() const;
	ATank* GetPlayerTank() const;
};
