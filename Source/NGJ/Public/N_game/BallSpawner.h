// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "N_game/PlayerBall.h"
#include "N_game/OtherBallBase.h"
#include "BallSpawner.generated.h"

UCLASS()
class NGJ_API ABallSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABallSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SpawnAreaX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SpawnAreaY;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	APlayerBall* thePlayer;

	//距下次尝试进行一次生成的时间
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float spawnTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float flashTime;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	bool isStarted;

	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SpawnBall(FVector spawnLocation);
	virtual void SpawnBall_Implementation(FVector spawnLocation);
};
