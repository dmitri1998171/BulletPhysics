// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileComponent.h"

UProjectileComponent::UProjectileComponent() {
    EnableLog = true;
    EnableGravity = true;
    Gravity = FVector(0, 0, GRAVITY);
    Mass = 50;
    
    Parent = GetOwner();
    if (Parent != nullptr) {
        PlayerPos = Parent->GetActorLocation();
        BoundingBox = Parent->GetComponentsBoundingBox();
    }
}

void UProjectileComponent::BeginPlay()
{
    Super::BeginPlay();

    Force += Impulse;
    CalculateValues();
}

void UProjectileComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    
    UseGravity();
    
    float X = (((AirResist + Wind) * Sk) + Gravity.GetComponentForAxis(EAxis::X));// * DeltaTime;
    float Y = (((AirResist + Wind) * Sk) + Gravity.GetComponentForAxis(EAxis::Y));// * DeltaTime;
    float Z = (((AirResist + Wind) * Sk) + Gravity.GetComponentForAxis(EAxis::Z));// * DeltaTime;
    
//    Force.Set(X, Y, Z);
//    Force += (Gravity + ((AirResist + Wind) * Sk));// * DeltaTime;
    
    PlayerPos = Parent->GetActorLocation();
    Parent->SetActorLocation(PlayerPos + Force);
    
    showLog(DeltaTime);
}

void UProjectileComponent::CalculateValues() {
    float X = Mass * Velocity.GetComponentForAxis(EAxis::X);
    float Y = Mass * Velocity.GetComponentForAxis(EAxis::Y);
    float Z = Mass * Velocity.GetComponentForAxis(EAxis::Z);
    
    Impulse.Set(X, Y, Z);
}

void UProjectileComponent::UseGravity() {
    if (!EnableGravity) {
        Gravity = FVector(0, 0, 0);
    }
}

void UProjectileComponent::showLog(float DeltaTime) {
    if(EnableLog && Parent) {
        PlayerPos = Parent->GetActorLocation();
        BoundingBox = Parent->GetComponentsBoundingBox();
        
//        GEngine->AddOnScreenDebugMessage(-1, DeltaTime, FColor::Red, FString::Printf(TEXT("bbox: %s"), *BoundingBox.ToString()));
//        GEngine->AddOnScreenDebugMessage(-1, DeltaTime, FColor::Red, FString::Printf(TEXT("bbox Volume: %f"), BoundingBox.GetVolume()));
        
        GEngine->AddOnScreenDebugMessage(-1, DeltaTime, FColor::Red, FString::Printf(TEXT("Gravity: %s"), *Gravity.ToString()));
        GEngine->AddOnScreenDebugMessage(-1, DeltaTime, FColor::Red, FString::Printf(TEXT("Impulse: %s"), *Impulse.ToString()));
        GEngine->AddOnScreenDebugMessage(-1, DeltaTime, FColor::Red, FString::Printf(TEXT("Force: %s"), *Force.ToString()));
        
        GEngine->AddOnScreenDebugMessage(-1, DeltaTime, FColor::Green, FString::Printf(TEXT("pos: %s"), *PlayerPos.ToString()));
    }
}
