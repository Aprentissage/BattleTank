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

ATank* ATankPlayerControer::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());

}

void ATankPlayerControer::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }
	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("HitLocation is: %s"), *HitLocation.ToString());
	}
	

}

bool ATankPlayerControer::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	OutHitLocation = FVector(1.0);
	return true;
}
