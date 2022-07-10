// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/MovementComponent.h"
#include "ProjectileComponent.generated.h"

#define GRAVITY -9.8

UCLASS()
class BULLETPHYSICS_API UProjectileComponent : public UMovementComponent
{
	GENERATED_BODY()
	
    AActor* Parent;
    FVector PlayerPos;
    FBox BoundingBox;
    
    FBox MeshBBox;

    FVector Force;
    FVector Impulse;
    
public:
    
    UProjectileComponent();
    
    void BeginPlay();
    
    void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction);
    
    UPROPERTY(EditAnywhere, Category = Log)
    bool EnableLog;

    
    UPROPERTY(EditAnywhere, Category = Physics)
    bool EnableGravity;

    UPROPERTY(EditAnywhere, Category = Physics)
    FVector Gravity;

    
    UPROPERTY(EditAnywhere, Category = "Physics\|Material")
    float Mass;

//    UPROPERTY(EditAnywhere, Category = "Physics")
//    FVector Velocity;     // стартовая Скорость снаряда (зависит от типа орудия, из котор. стреляют)

    
    UPROPERTY(EditAnywhere, Category = "Physics")
    float AirResist;    // Сопротивление воздуха
    
    UPROPERTY(EditAnywhere, Category = "Physics")
    float Wind;         // Ветер
    
    UPROPERTY(EditAnywhere, Category = "Physics")
    float Sk;           // Sk - коэф. площади (на сколько ветер воздействует на объект)
    
    
    UFUNCTION()
    void UseGravity();

    UFUNCTION()
    void showLog(float DeltaTime);

    UFUNCTION()
    void CalculateValues();
};
