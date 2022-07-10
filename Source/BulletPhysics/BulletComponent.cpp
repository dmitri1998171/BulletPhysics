// Fill out your copyright notice in the Description page of Project Settings.


#include "BulletComponent.h"

// Sets default values for this component's properties
UBulletComponent::UBulletComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

    isFired = true;
    EnableLog = true;
    
    EnableGravity = true;
    Gravity = FVector(0, 0, GRAVITY);
    
    Mass = 50;
    
    InitialSpeed = 1;
    
    AirResist = 1;
    Wind = 1;
    Sk = 0;
    
    Parent = GetOwner();
    if (Parent != nullptr) {
        PlayerPos = Parent->GetActorLocation();
        BoundingBox = Parent->GetComponentsBoundingBox();
    }
}


// Called when the game starts
void UBulletComponent::BeginPlay()
{
	Super::BeginPlay();
    
}


// Called every frame
void UBulletComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if(isFired)
    {
        float X = Mass * InitialSpeed * Velocity.X;
        float Y = Mass * InitialSpeed * Velocity.Y;
        float Z = Mass * InitialSpeed * Velocity.Z;
        
        Force.Set(X, Y, Z);
        
        isFired = false;
    }
    
    AddResistance(DeltaTime);

    PlayerPos = Parent->GetActorLocation();
    Parent->SetActorLocation(PlayerPos + Force);
    
    showLog(DeltaTime);
}

void UBulletComponent::AddResistance(float DeltaTime) {
    float value = ((AirResist + Wind) * Sk);
    
    if (!EnableGravity) {
        Gravity = FVector(0, 0, 0);
    }
    
    Force.X += (Gravity.X + value) * DeltaTime;
    Force.Y += (Gravity.Y + value) * DeltaTime;
    Force.Z += (Gravity.Z + value) * DeltaTime;
}

void UBulletComponent::showLog(float DeltaTime) {
    if(EnableLog && Parent) {
        PlayerPos = Parent->GetActorLocation();
        BoundingBox = Parent->GetComponentsBoundingBox();
        
//        GEngine->AddOnScreenDebugMessage(-1, DeltaTime, FColor::Red, FString::Printf(TEXT("bbox: %s"), *BoundingBox.ToString()));
//        GEngine->AddOnScreenDebugMessage(-1, DeltaTime, FColor::Red, FString::Printf(TEXT("bbox Volume: %f"), BoundingBox.GetVolume()));
        
        GEngine->AddOnScreenDebugMessage(-1, DeltaTime, FColor::Red, FString::Printf(TEXT("Force: %s"), *Force.ToString()));
        
        GEngine->AddOnScreenDebugMessage(-1, DeltaTime, FColor::Green, FString::Printf(TEXT("pos: %s"), *PlayerPos.ToString()));
    }
}
