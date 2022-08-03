// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "FPSProjectile.h"
#include "BulletComponent.h"
#include "FPSCharacter.generated.h"

UCLASS()
class BULLETPHYSICS_API AFPSCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFPSCharacter();
    
    FVector LaunchDirection;
    FVector CameraLocation;
    FRotator CameraRotation;
    FRotator MuzzleRotation;
    
    FVector tmpForce;
    
    FVector Start;
    FVector End;
    FVector tmp;
            
    FHitResult OutHit;
    FCollisionQueryParams CollisionParams;
        
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    
    // Handles input for moving forward and backward.
    UFUNCTION()
    void MoveForward(float Value);

    // Handles input for moving right and left.
    UFUNCTION()
    void MoveRight(float Value);
    
    // FPS camera.
    UPROPERTY(VisibleAnywhere)
    UCameraComponent* FPSCameraComponent;
    
    // Function that handles firing projectiles.
    UFUNCTION()
    void Fire();
    
    // Gun muzzle offset from the camera location.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
    FVector MuzzleOffset;
    
    // Projectile class to spawn.
    UPROPERTY(EditDefaultsOnly, Category = Projectile)
    TSubclassOf<class AFPSProjectile> ProjectileClass;
    
    // Projectile movement component.
    UPROPERTY(VisibleAnywhere, Category = Movement)
    UBulletComponent* ProjectileMovementComponent;
    
    // Projectile mesh
    UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
    UStaticMeshComponent* ProjectileMeshComponent;
    
    // Projectile material
    UPROPERTY(VisibleDefaultsOnly, Category = Movement)
    UMaterialInstanceDynamic* ProjectileMaterialInstance;
    
    UFUNCTION()
    void CollisionDetection(float DeltaTime);
};
