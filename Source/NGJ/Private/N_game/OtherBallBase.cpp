// Fill out your copyright notice in the Description page of Project Settings.


#include "N_game/OtherBallBase.h"

AOtherBallBase::AOtherBallBase() {
	thePower = 100000.f;
}

void AOtherBallBase::BeginPlay()
{
	Super::BeginPlay();
	
	thePlayer = Cast<APlayerBall>(GetWorld()->GetFirstPlayerController()->GetPawn());

	thePlayer->otherBalls.Add(this);

	if (theBall) {
		theBall->SetWorldScale3D(FVector(0,0,0));
	}
}

void AOtherBallBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (theBall) {
		theBall->SetWorldScale3D(FMath::Lerp(theBall->GetComponentScale(), FVector(1, 1, 1), 0.05));
	}

	if (thePlayer&& theBall->GetComponentScale().Length()>= 1.0f)
	{
		FVector direction = thePlayer->theBall->GetComponentLocation()- theBall->GetComponentLocation();
		direction.Normalize();

		double ClosingValue = FVector::DotProduct(theBall->GetComponentVelocity() - thePlayer->theBall->GetComponentVelocity(), direction);

		if (ClosingValue <= 100) {
			direction *= 100-ClosingValue;
			theBall->AddImpulse(direction);
		}

	}
}
