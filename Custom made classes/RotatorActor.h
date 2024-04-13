// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Math/Rotator.h"
#include "RotatorActor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CRYPTRAIDER_API URotatorActor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URotatorActor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void SetShouldRotate(bool ShouldRotate);
	

private:
	UPROPERTY(EditAnywhere)
	FRotator RotationOffset;

	FRotator OriginalRotation;

	UPROPERTY(EditAnywhere)
	float RotationTime = 2;
	bool ShouldRotate = false;

};
