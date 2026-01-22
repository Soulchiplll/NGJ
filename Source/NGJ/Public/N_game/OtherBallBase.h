// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "N_game/gameBall.h"
#include "N_game/PlayerBall.h"
#include "OtherBallBase.generated.h"

/**
 * 
 */
UCLASS()
class NGJ_API AOtherBallBase : public AgameBall
{
	GENERATED_BODY()
	

public:
	AOtherBallBase();

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	APlayerBall* thePlayer;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float thePower;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

};
