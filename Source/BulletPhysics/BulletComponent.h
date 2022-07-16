// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DrawDebugHelpers.h"
#include "BulletComponent.generated.h"

#define GRAVITY -9.8

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BULLETPHYSICS_API UBulletComponent : public UActorComponent
{
	GENERATED_BODY()

    bool isFired;
    
    AActor* Parent;
    FVector PlayerPos;
    FBox BoundingBox;

    FVector Impulse;
    
    FVector Start;
    FVector End;
        
public:
    // Sets default values for this component's properties
    UBulletComponent();

protected:
    // Called when the game starts
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    FVector Force;
    float ForceScale;   // Для компенсации умножения на вектор направления (Velocity)
    
    UPROPERTY(EditAnywhere, Category = Log)
    bool EnableLog;

    
    UPROPERTY(EditAnywhere, Category = "Physics")
    bool EnableGravity;

    UPROPERTY(EditAnywhere, Category = "Physics")
    FVector Gravity;
    
    UPROPERTY(EditAnywhere, Category = "Physics")
    float GravityScale;

    
    UPROPERTY(EditAnywhere, Category = "Physics")
    float Mass;

    
    // стартовая Скорость снаряда (зависит от типа орудия, из котор. стреляют)
    UPROPERTY(EditAnywhere, Category = "Physics")
    float InitialSpeed;
    
    FVector Velocity;

    
    // Ветер
    UPROPERTY(EditAnywhere, Category = "Physics\|Resistance")
    bool EnableWind;
    
    UPROPERTY(EditAnywhere, Category = "Physics\|Resistance")
    FVector Wind;
    
    
    // Сопротивление воздуха
    UPROPERTY(EditAnywhere, Category = "Physics\|Resistance")
    float AirResistance;
    
    // Коэф. площади (на сколько сильно ветер воздействует на объект)
    UPROPERTY(EditAnywhere, Category = "Physics\|Resistance")
    FVector SquareCoef;     // не равна 0 !!!
    
    UFUNCTION()
    void CalcForce();
    
    UFUNCTION()
    void AddResistance(float DeltaTime);

    UFUNCTION()
    void showLog(float DeltaTime);
    
    UFUNCTION()
    void DrawTrajectory();
};

/*
 
 Пуля:
    Скорость ~ 300-500 м/с пистолет; ~ 700-1000 м/с автомат
    Вес ~ 3-4 г
 
 Стрела:
    Скорость ~ до 100 м/с лук; ~ до 150 м/с арбалет
    Вес 13–17 гран на каждый кг натяжения (1 гран = 0,0648 г)
 */
