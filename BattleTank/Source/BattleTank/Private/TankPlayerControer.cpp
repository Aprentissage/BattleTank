// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleTank/Public/TankPlayerControer.h"

void ATankPlayerControer::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possesing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing: %s"),*(ControlledTank->GetName()));
	}
}

void ATankPlayerControer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
	
}

void ATankPlayerControer::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }
}

ATank* ATankPlayerControer::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());

}

