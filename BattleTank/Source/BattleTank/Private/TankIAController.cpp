// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleTank/Public/TankIAController.h"


void ATankIAController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController not possesing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController possessing: %s"), *(ControlledTank->GetName()));
	}
}

ATank* ATankIAController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
