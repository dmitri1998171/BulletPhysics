// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "BulletComponent.h"
#include "FPSProjectile.generated.h"

enum ProjectileReflection {
    FLYING = 0,
    DONT_PENETRATE = 1,
    PENETRATE,
    REBOUND,
    THROUGH
};

UCLASS()
class BULLETPHYSICS_API AFPSProjectile : public AActor
{
	GENERATED_BODY()
        
    FVector Cube;
    float _CubeSize;
    FQuat CubeRotation;
    
// ---------------------------
    
    AActor* _OtherActor;
//    UPrimitiveComponent* OtherActorComp;
    USceneComponent* OtherActorComp;
    FVector OtherActorVelocity;
    
    FVector OtherActorStart;
    FVector OtherActorEnd;
    
    float OtherActorRadius;
    
// ---------------------------
    
    bool CoordCalc;
    bool PastCoordCalc;
    FVector PastCoord;
    FVector CurrCoord;
    
// ---------------------------
    
    FVector ImpactPoint;  // точка пересечения
    
    float length;
    float time;
    
    float OtherActorLength;
    
// ---------------------------
    
    FVector BoxStart;
    
    TArray<FOverlapResult> BoxOverlapResult;
    FCollisionQueryParams BoxCollisionParams;
    
// ---------------------------
    
    TArray<FOverlapResult> ProjectileOverlapResult;
    FCollisionQueryParams ProjectileCollisionParams;
    
// ---------------------------
    
    FVector Start;
    FVector End;

    FHitResult LineOutHit;
    FCollisionQueryParams LineCollisionParams;
    
// ---------------------------
    
    float AttackAngle;          // Угол атаки снаряда к плоскости объекта (нужен для рассчета рикошета)
    float Density;              // Коэфф. плотности (должно находиться у объектов)
    float Density_percents;     // Процентное соотн. текущ. плотности к максимальному значению
    float PenetrationDepth;
    float MaxPenetrationDepth;
    
    FVector NewPos;
    int projectileState;
    
public:	
	// Sets default values for this actor's properties
	AFPSProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
    
    // Sphere collision component.
    UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
    USphereComponent* CollisionComponent;
    
    // Projectile movement component.
    UPROPERTY(VisibleAnywhere, Category = Movement)
    UBulletComponent* ProjectileMovementComponent;
    
    // Projectile mesh
    UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
    UStaticMeshComponent* ProjectileMeshComponent;
    
    // Projectile material
    UPROPERTY(VisibleDefaultsOnly, Category = Movement)
    UMaterialInstanceDynamic* ProjectileMaterialInstance;
    
    // Function that initializes the projectile's velocity in the shoot direction.
    void FireInDirection(const FVector& ShootDirection);
    
    // Function that is called when the projectile hits something.
    UFUNCTION()
    void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);
        
    UFUNCTION()
    void OnOverlap(class UPrimitiveComponent* Comp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
    UFUNCTION()
    void CollisionDetection();
    
    UFUNCTION()
    bool Cross(FVector a, FVector c, FVector b, FVector d);
    
    UFUNCTION()
    void BroadPhaseCollisionDetection(float DeltaTime);
    
    UFUNCTION()
    void CalcVelocity(FVector& DeltaVelocity);
    
    UFUNCTION()
    void NarrowPhaseCollisionDetection(bool isReverse);
    
    UFUNCTION()
    void ProjectileReflection();
};
