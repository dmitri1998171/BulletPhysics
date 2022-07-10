// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
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

    FVector Force;
    FVector Impulse;
    
public:	
	// Sets default values for this component's properties
	UBulletComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    
    UPROPERTY(EditAnywhere, Category = Log)
    bool EnableLog;

    
    UPROPERTY(EditAnywhere, Category = Physics)
    bool EnableGravity;

    UPROPERTY(EditAnywhere, Category = Physics)
    FVector Gravity;

    
    UPROPERTY(EditAnywhere, Category = "Physics\|Material")
    float Mass;

    
    UPROPERTY(EditAnywhere, Category = "Physics\|Speed")
    FVector Velocity;
    
    UPROPERTY(EditAnywhere, Category = "Physics\|Speed")
    float InitialSpeed;     // стартовая Скорость снаряда (зависит от типа орудия, из котор. стреляют)

    
    UPROPERTY(EditAnywhere, Category = "Physics\|Resistance")
    float AirResist;    // Сопротивление воздуха
    
    UPROPERTY(EditAnywhere, Category = "Physics\|Resistance")
    float Wind;         // Ветер
    
    UPROPERTY(EditAnywhere, Category = "Physics\|Resistance")
    float Sk;           // Sk - коэф. площади (на сколько ветер воздействует на объект)
    
        
    UFUNCTION()
    void AddResistance(float DeltaTime);

    UFUNCTION()
    void showLog(float DeltaTime);
};
