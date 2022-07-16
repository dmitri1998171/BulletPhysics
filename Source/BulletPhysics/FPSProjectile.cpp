// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSProjectile.h"

// Sets default values
AFPSProjectile::AFPSProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    
    if(!RootComponent)
    {
        RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("ProjectileSceneComponent"));
    }
    
    if(!CollisionComponent)
    {
        // Use a sphere as a simple collision representation.
        CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
        // Set the sphere's collision profile name to "Projectile".
        CollisionComponent->BodyInstance.SetCollisionProfileName(TEXT("Projectile"));
        // Event called when component hits something.
        CollisionComponent->OnComponentHit.AddDynamic(this, &AFPSProjectile::OnHit);
        // Set the sphere's collision radius.
        CollisionComponent->InitSphereRadius(15.0f);
        // Set the root component to be the collision component.
        RootComponent = CollisionComponent;
    }
    
    if(!ProjectileMovementComponent)
    {
        // Use this component to drive this projectile's movement.
        ProjectileMovementComponent = CreateDefaultSubobject<UBulletComponent>(TEXT("ProjectileMovementComponent"));
    }
    
    if (!ProjectileMeshComponent)
    {
        ProjectileMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMeshComponent"));
        static ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh(TEXT("'/Game/Sphere.Sphere'"));
        if (Mesh.Succeeded())
        {
            ProjectileMeshComponent->SetStaticMesh(Mesh.Object);
        }

        static ConstructorHelpers::FObjectFinder<UMaterial>Material(TEXT("'/Game/SphereMaterial.SphereMaterial'"));
        if (Material.Succeeded())
        {
            ProjectileMaterialInstance = UMaterialInstanceDynamic::Create(Material.Object, ProjectileMeshComponent);
        }
        ProjectileMeshComponent->SetMaterial(0, ProjectileMaterialInstance);
        ProjectileMeshComponent->SetRelativeScale3D(FVector(0.09f, 0.09f, 0.09f));
        ProjectileMeshComponent->SetupAttachment(RootComponent);
    }
    
    // Delete the projectile after 3 seconds.
    InitialLifeSpan = 3.0f;
}

// Called when the game starts or when spawned
void AFPSProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFPSProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    SetActorLocation(GetActorLocation() + ProjectileMovementComponent->Force);
    
    DrawDebugSphere(GetWorld(), GetActorLocation(), 300, 10, FColor::Magenta, false, DeltaTime* 1.5, 0, 3);
    
    
    
//    CollisionDetection(DeltaTime);

}

// Function that initializes the projectile's velocity in the shoot direction.
void AFPSProjectile::FireInDirection(const FVector& ShootDirection)
{
    ProjectileMovementComponent->Velocity = ShootDirection;
}

// Function that is called when the projectile hits something.
void AFPSProjectile::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
    if (OtherActor != this && OtherComponent->IsSimulatingPhysics())
    {
        OtherComponent->AddImpulseAtLocation(ProjectileMovementComponent->Velocity / 100, Hit.ImpactPoint);
    }

    Destroy();
}

void AFPSProjectile::CollisionDetection(float DeltaTime) {
//    UE_LOG(LogTemp, Warning, TEXT("Force: %s"), *ProjectileMovementComponent->Force.ToString());
    
    Start = GetActorLocation() + (ProjectileMovementComponent->Velocity * CollisionComponent->GetScaledSphereRadius());   // Домнажаем на Velocity чтобы отодвинуть точку старта только в направлении движ. снаряда. Иначе траектория будет проходить рядом, а не через снаряд;
    End = Start + ProjectileMovementComponent->Force;
    
    for (int i = 0; i < 1000; i++) {
        // Отрисовка линии
        DrawDebugLine(GetWorld(), Start, End, FColor::Yellow, false, DeltaTime * 1.5, 0, CollisionComponent->GetScaledSphereRadius());
        
        if(GetWorld()->LineTraceSingleByChannel(OutHit, Start, End, ECC_Visibility, CollisionParams)) {
            if(OutHit.GetActor() != this) {
                GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Yellow, FString::Printf(TEXT("You will hit: %s"), *OutHit.GetActor()->GetName()));
//                UE_LOG(LogTemp, Warning, TEXT("Collision detected: %s"), *OutHit.GetActor()->GetName());
            }
        }
        
        Start = End;
        End += ProjectileMovementComponent->Force;
    }
}

//void AFPSProjectile::IterateAllSceneObjects() {
//    for(TObjectIterator<UClass> It; It; ++It)
//     {
//         if(It->IsChildOf(USomeAwesomeClass::StaticClass()) && !It->HasAnyClassFlags(CLASS_Abstract))
//         {
//             Subclasses.Add(*It);
//         }
//     }
//}
