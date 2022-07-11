// Fill out your copyright notice in the Description page of Project Settings.


#include "BulletComponent.h"

// Sets default values for this component's properties
UBulletComponent::UBulletComponent() {
	PrimaryComponentTick.bCanEverTick = true;

    isFired = true;
    EnableLog = true;
    
    EnableGravity = true;
    Gravity = FVector(0, 0, GRAVITY);
    
/*   Система СИ: кг-м-с   */
    Mass = 0.009;
    
    InitialSpeed = 500;
    
    AirResist = 1;
    Wind = 1;
    Sk = 1;
    
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
        float X = Mass * InitialSpeed * Velocity.X * DeltaTime;
        float Y = Mass * InitialSpeed * Velocity.Y * DeltaTime;
        float Z = Mass * InitialSpeed * Velocity.Z * DeltaTime;
        
        Force.Set(X, Y, Z);
        
        isFired = false;
        Start = Parent->GetActorLocation();
    }
    
    AddResistance(DeltaTime);

    PlayerPos = Parent->GetActorLocation();
    Parent->SetActorLocation(PlayerPos + Force);
    
    DrawTrajectory();
    
    showLog(DeltaTime);
}

void UBulletComponent::AddResistance(float DeltaTime) {
    float value = ((AirResist + Wind) * Sk);
    
    if (!EnableGravity)
        Gravity = FVector(0, 0, 0);
    
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

void UBulletComponent::DrawTrajectory() {
    End = PlayerPos;
    DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 1, 0, 1);
    Start = End;
}
