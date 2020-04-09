// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank/BattleTank.h"
#include "BattleTank/Public/TankBarrel.h"

void UTankBarrel::Elevate(float DegreesPerSecond)
{
	UE_LOG(LogTemp, Warning, TEXT("Barrel Elevate Called: %f"), DegreesPerSecond);
}
