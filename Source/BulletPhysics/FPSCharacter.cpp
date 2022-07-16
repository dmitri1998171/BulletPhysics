// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSCharacter.h"

// Sets default values
AFPSCharacter::AFPSCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    
    if(!ProjectileMovementComponent)
    {
        // Use this component to drive this projectile's movement.
        ProjectileMovementComponent = CreateDefaultSubobject<UBulletComponent>(TEXT("ProjectileMovementComponent"));
    }
    
    // Create a first person camera component.
    FPSCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
    check(FPSCameraComponent != nullptr);

    // Attach the camera component to our capsule component.
    FPSCameraComponent->SetupAttachment(CastChecked<USceneComponent, UCapsuleComponent>(GetCapsuleComponent()));
    
    // Position the camera slightly above the eyes.
    FPSCameraComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f + BaseEyeHeight));

    // Enable the pawn to control camera rotation.
    FPSCameraComponent->bUsePawnControlRotation = true;
}

// Called when the game starts or when spawned
void AFPSCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFPSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    GetActorEyesViewPoint(CameraLocation, CameraRotation);
    MuzzleRotation = CameraRotation;
    MuzzleRotation.Pitch += 2.5;    // Чтоб снаряд пролетал через прицел
    
    LaunchDirection = MuzzleRotation.Vector();
    
    // Проверка столкновения с лучом
//    CollisionDetection(DeltaTime);
}

// Called to bind functionality to input
void AFPSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

    // Set up "movement" bindings.
    PlayerInputComponent->BindAxis("MoveForward", this, &AFPSCharacter::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &AFPSCharacter::MoveRight);

    // Set up "look" bindings.
    PlayerInputComponent->BindAxis("Turn", this, &AFPSCharacter::AddControllerYawInput);
    PlayerInputComponent->BindAxis("LookUp", this, &AFPSCharacter::AddControllerPitchInput);
    
    
    PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AFPSCharacter::Fire);
}

void AFPSCharacter::MoveForward(float Value)
{
    // Find out which way is "forward" and record that the player wants to move that way.
    FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
    AddMovementInput(Direction, Value);
}

void AFPSCharacter::MoveRight(float Value)
{
    // Find out which way is "right" and record that the player wants to move that way.
    FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
    AddMovementInput(Direction, Value);
}

void AFPSCharacter::Fire()
{
    // Attempt to fire a projectile.
    if (ProjectileClass)
    {
        MuzzleOffset.Set(100.0f, 0.0f, 0.0f);

        // Transform MuzzleOffset from camera space to world space.
        FVector MuzzleLocation = CameraLocation + FTransform(CameraRotation).TransformVector(MuzzleOffset);

        UWorld* World = GetWorld();
        if (World)
        {
            FActorSpawnParameters SpawnParams;
            SpawnParams.Owner = this;
            SpawnParams.Instigator = GetInstigator();

            // Spawn the projectile at the muzzle.
            AFPSProjectile* Projectile = World->SpawnActor<AFPSProjectile>(ProjectileClass, MuzzleLocation, MuzzleRotation, SpawnParams);
            if (Projectile)
            {
                // Set the projectile's initial trajectory.
                Projectile->FireInDirection(LaunchDirection);
            }
        }
    }
}

void AFPSCharacter::CollisionDetection(float DeltaTime) {
    ProjectileMovementComponent->Velocity = LaunchDirection;
    ProjectileMovementComponent->CalcForce();
    ProjectileMovementComponent->AddResistance(DeltaTime);
    
//    UE_LOG(LogTemp, Warning, TEXT("Force: %s"), *ProjectileMovementComponent->Force.ToString());
    
    Start = GetActorLocation();
    End = Start + ProjectileMovementComponent->Force;
    
    for (int i = 0; i < 1000; i++) {
        // Отрисовка линии
        DrawDebugLine(GetWorld(), Start, End, FColor::Red, false, DeltaTime * 1.5, 0, 5);
        
        if(GetWorld()->LineTraceSingleByChannel(OutHit, Start, End, ECC_Visibility, CollisionParams)) {
            GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, FString::Printf(TEXT("You will hit: %s"), *OutHit.GetActor()->GetName()));
        }
        
        Start = End;
        End += ProjectileMovementComponent->Force;
        ProjectileMovementComponent->AddResistance(DeltaTime * 0.4);
    }
}
