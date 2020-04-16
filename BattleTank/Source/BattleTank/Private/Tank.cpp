// Fill out your copyright notice in the Description page of Project Settings.
#include "BattleTank/Public/TankBarrel.h"
#include "Engine/World.h"
#include "BattleTank/Public/TankAimingComponent.h"
#include "BattleTank/Public/Tank.h"
#include "BattleTank/Public/Projectile.h"
#include "TankMouvementComponent.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	
}







void ATank::AimAt(FVector Hitlocation)
{
	TankAimingComponent->AimAt(Hitlocation, LaunchSpeed);
}

void ATank::fire()
{

	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;
	if (Barrel && isReloaded)
	{
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile"))
			);
		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
}
