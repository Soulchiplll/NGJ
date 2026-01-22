// Fill out your copyright notice in the Description page of Project Settings.


#include "N_game/gameBall.h"

// Sets default values
AgameBall::AgameBall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AgameBall::BeginPlay()
{
	Super::BeginPlay();
	
	theBall = GetComponentByClass<UStaticMeshComponent>();
}

// Called every frame
void AgameBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

