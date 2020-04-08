// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleTank/Public/TankIAController.h"


void ATankIAController::BeginPlay()
{
	Super::BeginPlay();

	auto PCTank = GetPlayerTank();
	if (!PCTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController not Finding the PCtank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController Found the PCTank as: %s"), *(PCTank->GetName()));
	}
}

void ATankIAController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!GetControlledTank()) { return; }
	else	
	{
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	}
}

ATank* ATankIAController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankIAController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}
