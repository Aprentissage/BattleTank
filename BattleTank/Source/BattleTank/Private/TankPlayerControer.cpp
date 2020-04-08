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
		//UE_LOG(LogTemp, Warning, TEXT("HitLocation is: %s"), *HitLocation.ToString());
	}
	

}

bool ATankPlayerControer::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		UE_LOG(LogTemp, Warning, TEXT("look direction is: %s"), *LookDirection.ToString());
	}
	return true;
}

bool ATankPlayerControer::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation;
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
	
}

