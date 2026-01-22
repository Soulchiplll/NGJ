// Fill out your copyright notice in the Description page of Project Settings.

#include "N_game/OtherBallBase.h"
#include "N_game/PlayerBall.h"


void APlayerBall::BeginPlay()
{
	Super::BeginPlay();

	isSheild = true;
	theChosenBall = nullptr;
	isRounding = false;
	LightIntensity = 0.2f;
}

void APlayerBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	reChoseTime += DeltaTime;
	if (reChoseTime >= 0.1f && !isRounding) {
		AOtherBallBase* closestBall = nullptr;
		//计算距离最近的球
		for (AOtherBallBase* ball : otherBalls) {
			if (!closestBall || FVector::Dist(theBall->GetComponentLocation(), ball->theBall->GetComponentLocation()) < FVector::Dist(theBall->GetComponentLocation(), closestBall->theBall->GetComponentLocation())) {
				closestBall = ball;
			}
		}
		
	theChosenBall = closestBall;
	
		reChoseTime = 0.f;
	}

	if (LightComp) {
		LightIntensity = FMath::Lerp(LightIntensity, 0.2f, 0.1f);
		LightComp->SetIntensity(LightIntensity);
	}
}

void APlayerBall::Round() {
	if (!theChosenBall) return;

	FVector direction = theChosenBall->theBall->GetComponentLocation() - theBall->GetComponentLocation();
	direction.Normalize();
	//direction *= thePower;
	FVector tanDirection = FVector::CrossProduct(direction, FVector(1, 0, 0));
	tanDirection.Normalize();
	tanDirection *= 1000;
	double distance = FVector::Distance(theChosenBall->theBall->GetComponentLocation(), theBall->GetComponentLocation());
	//要计算（1,0,0）和direction的叉乘

	theBall->AddForce(tanDirection*109);
	theChosenBall->theBall->AddForce(tanDirection*-109);
	FVector centre = (theChosenBall->theBall->GetComponentLocation() + theBall->GetComponentLocation());
	FVector toCentre = centre - theBall->GetComponentLocation();
	double centripelForce = FVector::DotProduct(theBall->GetComponentVelocity(), theBall->GetComponentVelocity()) * theBall->GetMass() / toCentre.Size();

	if (distance>=100) {
		float zuni = -100;

		theBall->AddForce(direction * centripelForce*1.2);
		theBall->AddForce(theBall->GetComponentVelocity()*zuni);
		theChosenBall->theBall->AddForce(direction * -centripelForce*1.2);
		theChosenBall->theBall->AddForce(theChosenBall->theBall->GetComponentVelocity() * zuni);


	}

	//GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Green, FString::Printf(TEXT("Centripel Force:%f"), centripelForce));
}

void APlayerBall::AddSheild() {
	if (isSheild) {
		SheildBack = true;
		SheildBroken();
		return;
	}
	isSheild = true;
}

void APlayerBall::SheildBroken_Implementation() {
	isSheild = false;
}

void APlayerBall::FlashLight(double a =100.f) {
	LightIntensity = a;
}