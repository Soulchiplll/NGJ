// Fill out your copyright notice in the Description page of Project Settings.


#include "N_game/TheTag.h"

// Sets default values
ATheTag::ATheTag()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATheTag::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATheTag::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

