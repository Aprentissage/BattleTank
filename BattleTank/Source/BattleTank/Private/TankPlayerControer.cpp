// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerControer.h"


ATank* ATankPlayerControer::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}