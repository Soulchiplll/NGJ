// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "N_game/gameBall.h"
#include "N_game/TheTag.h"
#include "Components/DirectionalLightComponent.h"
#include "PlayerBall.generated.h"


class AOtherBallBase;
/**
 * 
 */
UCLASS()
class NGJ_API APlayerBall : public AgameBall
{
	GENERATED_BODY()

public:
	virtual void Tick(float DeltaTime) override;

	//距离最近的目标球
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AOtherBallBase* theChosenBall;

	//重新选择目标的计时器
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float reChoseTime;

	//是否拥有护盾
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	bool isSheild;

	//是否正在环绕，防止更改目标
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool isRounding;

	//场上全部敌人球列表
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TArray<AOtherBallBase*> otherBalls;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<AOtherBallBase*> hiddenBalls;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<AOtherBallBase*> tempBalls;

	//该状态用于的护盾爆开后立即重新获得护盾
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool SheildBack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float LightIntensity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UDirectionalLightComponent* LightComp;

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void FlashLight(double a);
		
	UFUNCTION(BlueprintCallable)
	void Round();

	UFUNCTION(BlueprintCallable)
	void AddSheild();

	UFUNCTION(BlueprintNativeEvent,BlueprintCallable)
	void SheildBroken();
	virtual void SheildBroken_Implementation();
};
