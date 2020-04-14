// Fill out your copyright notice in the Description page of Project Settings.

#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "BattleTank/Public/Tank.h"
#include "BattleTank/Public/TankIAController.h"


void ATankIAController::BeginPlay()
{
	Super::BeginPlay();

}

void ATankIAController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());
	if (!PlayerTank) { return; }
	else	
	{
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		ControlledTank->fire();
	}
}



