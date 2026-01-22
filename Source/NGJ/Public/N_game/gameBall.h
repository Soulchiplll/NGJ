// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/Vector.h"
#include "Kismet/GameplayStatics.h"
#include "gameBall.generated.h"

UCLASS()
class NGJ_API AgameBall : public APawn
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AgameBall();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* theBall;

};
