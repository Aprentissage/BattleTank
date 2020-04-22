// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAimingComponent.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "BattleTank/Public/TankIAController.h" 


void ATankIAController::BeginPlay()
{
	Super::BeginPlay();

}

void ATankIAController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		auto PossessedTank = Cast<ATank>(InPawn);
		if (!PossessedTank) { return; }
		PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankIAController::OnPossedDeath);
	}
	
}

void ATankIAController::OnPossedDeath()
{
	if (!GetPawn()) { return; }
	GetPawn()->DetachFromControllerPendingDestroy();
}


void ATankIAController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();
	if (!(PlayerTank && ControlledTank)) { return; }
	
	MoveToActor(PlayerTank, AcceptanceRadius);
	auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
	AimingComponent->AimAt(PlayerTank->GetActorLocation());
	if (AimingComponent->GetFiringState() == EFiringState::Locked)
	{
		AimingComponent->fire();
	}
}




