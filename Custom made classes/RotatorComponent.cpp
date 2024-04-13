// Fill out your copyright notice in the Description page of Project Settings.


#include "RotatorComponent.h"

URotatorComponent::URotatorComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
}

void URotatorComponent::BeginPlay()
{
	Super::BeginPlay();
}

void URotatorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    AActor* Actor = GetAcceptableActor();
    if(Actor != nullptr)
    {
        UPrimitiveComponent* Component = Cast<UPrimitiveComponent> (Actor -> GetRootComponent());
        if (Component != nullptr)
        {
            Component -> SetSimulatePhysics(false);
        }
        Actor -> AttachToComponent(this, FAttachmentTransformRules::KeepWorldTransform);
        Rot -> SetShouldRotate(true);
    }
    else
    {
        Rot -> SetShouldRotate(false);
    }

}

void URotatorComponent::SetRotator(URotatorActor* NewRotator)
{
    Rot = NewRotator;
}

AActor* URotatorComponent::GetAcceptableActor() const
{
    TArray<AActor*> Actors;
    GetOverlappingActors(Actors);
    
    for(AActor* Actor : Actors)
    {   
        bool HasAcceptableTag = Actor -> ActorHasTag(AcceptableActorTag);
        bool IsGrabbed = Actor -> ActorHasTag("Grabbed");
        if(HasAcceptableTag && !IsGrabbed)
        {
            return Actor;
        }     
    }
    return nullptr;
}