// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine/World.h"
#include "BattleTank/BattleTank.h"
#include "BattleTank/Public/TankTurret.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto AzimuthChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto NewAzimuth = RelativeRotation.Yaw + AzimuthChange;
	SetRelativeRotation(FRotator(0, NewAzimuth, 0));
}
