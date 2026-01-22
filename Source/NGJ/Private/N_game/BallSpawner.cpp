// Fill out your copyright notice in the Description page of Project Settings.


#include "N_game/BallSpawner.h"

// Sets default values
ABallSpawner::ABallSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	isStarted = false;

	SpawnAreaX = 3700.f;
	SpawnAreaY = 2500.f;

	spawnTime = FMath::FRandRange(2.f, 4.5f);
	flashTime = FMath::FRandRange(15.f, 25.f);
}

// Called when the game starts or when spawned
void ABallSpawner::BeginPlay()
{
	Super::BeginPlay();
	
	thePlayer = Cast<APlayerBall>(GetWorld()->GetFirstPlayerController()->GetPawn());

}

// Called every frame
void ABallSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	spawnTime -= DeltaTime;
	flashTime -= DeltaTime;
	if(spawnTime<=0.f && isStarted && thePlayer) {
		spawnTime = FMath::FRandRange(2.f, 4.5f);
		FVector spawnLoc;
		spawnLoc.X = 0.f;
		spawnLoc.Y = FMath::FRandRange(-SpawnAreaX/2, SpawnAreaX/2);
		spawnLoc.Z = FMath::FRandRange(-SpawnAreaY/2, SpawnAreaY/2);

		SpawnBall(spawnLoc);
	}
	if(flashTime<= 0.f && isStarted && thePlayer) {
		flashTime = FMath::FRandRange(6.f, 8.f);
		//иа╧Б
		thePlayer->FlashLight(100.0);
		thePlayer->tempBalls.Reset();
		for(AOtherBallBase* ball : thePlayer->hiddenBalls) {
			thePlayer->tempBalls.Add(ball);
		}
			thePlayer->hiddenBalls.Reset();

		for(AOtherBallBase* ball : thePlayer->otherBalls) {
			ball->SetActorEnableCollision(false);
			ball->SetActorHiddenInGame(true);
			ball->SetActorTickEnabled(false);
			ball->theBall->SetSimulatePhysics(false);
			thePlayer->hiddenBalls.Add(ball);
		}
			thePlayer->otherBalls.Reset();

		for(AOtherBallBase* ball : thePlayer->tempBalls) {
			ball->SetActorEnableCollision(true);
			ball->SetActorHiddenInGame(false);
			ball->SetActorTickEnabled(true);
			ball->theBall->SetSimulatePhysics(true);	
			thePlayer->otherBalls.Add(ball);
		}
			thePlayer->tempBalls.Reset();
	}
}

void ABallSpawner::SpawnBall_Implementation(FVector spawnLocation) {
	FActorSpawnParameters spawnParams;
	spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::DontSpawnIfColliding;
	FVector worldLoc = GetActorLocation() + spawnLocation;
	AOtherBallBase* newBall = GetWorld()->SpawnActor<AOtherBallBase>(AOtherBallBase::StaticClass(), worldLoc, FRotator::ZeroRotator, spawnParams);
	if (newBall) {
		newBall->thePlayer = thePlayer;
	}
}