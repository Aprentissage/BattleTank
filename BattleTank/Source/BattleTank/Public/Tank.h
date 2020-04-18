// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

//Forward declerations
class UTankBarrel;
class AProjectile;


UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Firing")
	void fire();



private:	


	//UPROPERTY(EditAnywhere, Category = "Firing")
	float LaunchSpeed = 40000; // 1000m/s

	UPROPERTY(EditAnywhere, Category = "Firing")
	float ReloadTimeInSeconds = 3;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UTankBarrel* Barrel = nullptr;
	double LastFireTime = 0;
};
