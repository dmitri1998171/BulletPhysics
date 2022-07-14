// Fill out your copyright notice in the Description page of Project Settings.


#include "BulletComponent.h"

// Sets default values for this component's properties
UBulletComponent::UBulletComponent() {
	PrimaryComponentTick.bCanEverTick = true;

    isFired = true;
    EnableLog = true;
    
    EnableGravity = true;
    Gravity = FVector(0, 0, GRAVITY);
    GravityScale = 0.1;
    
/*   Система СИ: кг-м-с   */
    Mass = 0.004;
    
    InitialSpeed = 500;
    
    EnableWind = true;
    Wind = FVector(1, 0, 0);
    
    AirResistance = 1;
    SquareCoef = FVector(1, 1, 0);

    Parent = GetOwner();
    if (Parent != nullptr) {
        PlayerPos = Parent->GetActorLocation();
        BoundingBox = Parent->GetComponentsBoundingBox();
    }
}


// Called when the game starts
void UBulletComponent::BeginPlay() {
	Super::BeginPlay();
}


// Called every frame
void UBulletComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

//    Здесь костыль, потому что изменение Velocity(выбор направления) происходит после вызова BeginPlay()
    if(isFired) {
        float X = Mass * InitialSpeed * Velocity.X * 10;
        float Y = Mass * InitialSpeed * Velocity.Y * 10;
        float Z = Mass * InitialSpeed * Velocity.Z * 10;

        Force.Set(X, Y, Z);

        isFired = false;
        Start = Parent->GetActorLocation();
    }
    
    AddResistance(DeltaTime);

    PlayerPos = Parent->GetActorLocation();
    Parent->SetActorLocation(PlayerPos + Force);
    
//    DrawDebugLine(GetWorld(), PlayerPos, Velocity * 10000, FColor::Red, false, 1, 0, 1);
    DrawTrajectory();
    
    showLog(DeltaTime);
}

void UBulletComponent::AddResistance(float DeltaTime) {
    if (EnableGravity)
        Force += Gravity * GravityScale * DeltaTime;
    
    if (EnableWind)
        Force -= Wind * DeltaTime;
    
    SquareCoef *= AirResistance;
    Force -= SquareCoef * Velocity * DeltaTime;
}

void UBulletComponent::showLog(float DeltaTime) {
    if(EnableLog && Parent) {
        PlayerPos = Parent->GetActorLocation();
        BoundingBox = Parent->GetComponentsBoundingBox();
        
//        GEngine->AddOnScreenDebugMessage(-1, DeltaTime, FColor::Red, FString::Printf(TEXT("bbox: %s"), *BoundingBox.ToString()));
//        GEngine->AddOnScreenDebugMessage(-1, DeltaTime, FColor::Red, FString::Printf(TEXT("bbox Volume: %f"), BoundingBox.GetVolume()));

        GEngine->AddOnScreenDebugMessage(-1, DeltaTime, FColor::Red, FString::Printf(TEXT("Velocity: %s"), *Velocity.ToString()));
        
        GEngine->AddOnScreenDebugMessage(-1, DeltaTime, FColor::Red, FString::Printf(TEXT("Force: %s"), *Force.ToString()));
        
        GEngine->AddOnScreenDebugMessage(-1, DeltaTime, FColor::Green, FString::Printf(TEXT("pos: %s"), *PlayerPos.ToString()));
    }
}

void UBulletComponent::DrawTrajectory() {
    End = PlayerPos;
    DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 1, 0, 5);
    Start = End;
}
