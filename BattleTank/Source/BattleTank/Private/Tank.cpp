// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleTank/Public/TankBarrel.h"
#include "Engine/World.h"
#include "BattleTank/Public/Tank.h"
#include "BattleTank/Public/Projectile.h"




float ATank::GetHealthPercent() const
{
	return (float)CurrentHealth / (float)StartingHealth; // -> cast int32 CurrentHealth and StartingHealth to float (float)XXXX
}

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	
}


float ATank::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	int32 DamagePoints = FPlatformMath::RoundToInt(DamageAmount);
	int32 DamageToApply = FMath::Clamp(DamagePoints, 0, CurrentHealth);

	CurrentHealth -= DamageToApply;
	if (CurrentHealth <= 0)
	{

	}

	return DamageToApply;
}
