// Fill out your copyright notice in the Description page of Project Settings.


#include "RotatorActor.h"

// Sets default values for this component's properties
URotatorActor::URotatorActor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void URotatorActor::BeginPlay()
{
	Super::BeginPlay();
	OriginalRotation = GetOwner() -> GetActorRotation();
}


// Called every frame
void URotatorActor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if(ShouldRotate)
	{	
		UE_LOG(LogTemp, Display, TEXT("Rotating"));

		FRotator CurrentRotation = GetOwner() -> GetActorRotation();
		FRotator TargetRotation = OriginalRotation + RotationOffset;
		float Speed = RotationOffset.Euler().Length() / RotationTime;
		
		FRotator NewRotation = FMath::RInterpConstantTo(CurrentRotation, TargetRotation, DeltaTime, Speed);
		GetOwner() -> SetActorRelativeRotation(NewRotation);
		
	}
}


void URotatorActor::SetShouldRotate(bool NewShouldRotate)
{
	ShouldRotate = NewShouldRotate;
}
