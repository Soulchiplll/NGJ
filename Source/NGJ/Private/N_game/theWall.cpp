// Fill out your copyright notice in the Description page of Project Settings.


#include "N_game/theWall.h"

// Sets default values
AtheWall::AtheWall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AtheWall::BeginPlay()
{
	Super::BeginPlay();
	
	thePlayer = Cast<APlayerBall>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

// Called every frame
void AtheWall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

