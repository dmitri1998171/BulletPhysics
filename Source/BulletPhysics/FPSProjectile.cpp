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
        
        CollisionComponent->SetNotifyRigidBodyCollision(true);
        
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
    
    CoordCalc = false;
    PastCoordCalc = false;
    
    IsHited = false;
    Called = false;
    
    k = 0.5;
    AttackAngle = 0;
    
    _CubeSize = CollisionComponent->GetScaledSphereRadius() * 2;
}

// Called when the game starts or when spawned
void AFPSProjectile::BeginPlay()
{
	Super::BeginPlay();
    
    // Event called when component hits something.
    CollisionComponent->OnComponentHit.AddDynamic(this, &AFPSProjectile::OnHit);
}

// Called every frame
void AFPSProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    if( ! IsHited) {
        SetActorLocation(GetActorLocation() + ProjectileMovementComponent->Force);
//        BroadPhaseCollisionDetection(DeltaTime);
    }
    else {
//        ProjectileReflection();
    }
        
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
    UE_LOG(LogTemp, Warning, TEXT("Name: %s"), *OtherActor->GetName());
    UE_LOG(LogTemp, Warning, TEXT("Normal: %s"), *Hit.Normal.ToString());
    
    if (OtherActor != this) {
        if(OtherComponent->IsSimulatingPhysics()) {
            AttackAngle = ProjectileMovementComponent->Force.CosineAngle2D(Hit.Normal);
            UE_LOG(LogTemp, Warning, TEXT("Cos(AttackAngle): %f"), AttackAngle);
            
            
//            OtherComponent->AddImpulseAtLocation(ProjectileMovementComponent->Velocity, Hit.ImpactPoint);
        }
    }

    Destroy();
}

void AFPSProjectile::CollisionDetection(float DeltaTime) {
    Start = GetActorLocation() + (ProjectileMovementComponent->Velocity * CollisionComponent->GetScaledSphereRadius());   // Домнажаем на Velocity чтобы отодвинуть точку старта только в направлении движ. снаряда. Иначе траектория будет проходить рядом, а не через снаряд;
    End = Start + ProjectileMovementComponent->Force;
    
    for (int i = 0; i < 250; i++) {
        DrawDebugLine(GetWorld(), Start, End, FColor::Yellow, false, DeltaTime * 1.5, 0, CollisionComponent->GetScaledSphereRadius());
        
        if(GetWorld()->LineTraceSingleByChannel(LineOutHit, Start, End, ECC_Visibility, LineCollisionParams)) {
            if(LineOutHit.GetActor() != this) {
                GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Yellow, FString::Printf(TEXT("You will hit: %s"), *LineOutHit.GetActor()->GetName()));
//                UE_LOG(LogTemp, Warning, TEXT("Collision detected: %s"), *LineOutHit.GetActor()->GetName());
            }
        }
        
        Start = End;
        End += ProjectileMovementComponent->Force;
    }
}

bool AFPSProjectile::cross(FVector a, FVector c, FVector b, FVector d) {
    float n;
//    https://habr.com/ru/post/523440/
    
/*
    a - текущ. позиция
    b - force
    c - позиция др. объекта
    d - velocity др. объекта
*/
    
        if (b.Y - a.Y != 0) {  // a(y)
            float q = (b.X - a.X) / (a.Y - b.Y);
            float sn = (c.X - d.X) + (c.Y - d.Y) * q; if (!sn) { return 0; }  // c(x) + c(y)*q
            float fn = (c.X - a.X) + (c.Y - a.Y) * q;                         // b(x) + b(y)*q
            n = fn / sn;
        }
        else {
            if (!(c.Y - d.Y)) { return 0; }    // b(y)
            n = (c.Y - a.Y) / (c.Y - d.Y);     // c(y)/b(y)
        }
    
        ImpactPoint.X = c.X + (d.X - c.X) * n;  // c.X + (-b(x))*n
        ImpactPoint.Y = c.Y + (d.Y - c.Y) * n;  // c.Y + (-b(y))*n
        return 1;
}

void AFPSProjectile::BroadPhaseCollisionDetection(float DeltaTime) {
    Start = GetActorLocation();
    End = Start + (ProjectileMovementComponent->Force * 100);
    DrawDebugLine(GetWorld(), Start, End, FColor::Yellow, false, DeltaTime * 1.5, 0, 5);

    Cube = FVector(ProjectileMovementComponent->Force.GetAbsMax(), _CubeSize, _CubeSize);
    
    CubeRotation = ProjectileMovementComponent->Force.ToOrientationQuat();
    BoxStart = GetActorLocation() + (ProjectileMovementComponent->Velocity * (CollisionComponent->GetScaledSphereRadius() + ProjectileMovementComponent->Force.GetAbsMax()));
    DrawDebugBox(GetWorld(), BoxStart, Cube, CubeRotation, FColor::Magenta, false, DeltaTime * 1.5, 0, 3);
    
//    DrawDebugBox(GetWorld(), FVector(0, 0, 0), Cube, FQuat(0, 0, 0, 0), FColor::Yellow, false, DeltaTime * 1.5, 0, 3);
    
// Проверяем проникновение внутрь "коридора"
    if(GetWorld()->OverlapMultiByChannel(BoxOverlapResult, GetActorLocation(), CubeRotation, ECC_Visibility, FCollisionShape::MakeBox(Cube), BoxCollisionParams)) {
        
//        Проходимся по всем элементам, проникщих внутрь "коридора", и отсеиваем лишнее
        for (int i = 0; i < BoxOverlapResult.Num(); i++) {
            if(BoxOverlapResult[i].GetActor() != this) {
                _OtherActor = BoxOverlapResult[i].GetActor();
//                OtherActorComp = BoxOverlapResult[i].GetComponent();
                OtherActorComp = _OtherActor->GetRootComponent();
                CalcVelocity(OtherActorVelocity);
            }
        }

//        Проверка столкновений с движущимися объектами 
        if(OtherActorVelocity.IsZero() == false) {
//            UE_LOG(LogTemp, Warning, TEXT("%s's Velocity: %s"), *_OtherActor->GetName(), *OtherActorVelocity.ToString());

            /*
             Вычисления работают только для объектов, движущихся через физику (Velocity). При движении по сплайну нормально прочитать Velocity и нарисовать траекторию невозможно!
             Velocity высчитывается только при вкл. симуляции физики!
            */

            OtherActorStart = _OtherActor->GetActorLocation();
            OtherActorEnd = OtherActorStart + (OtherActorVelocity * 90);
            DrawDebugLine(GetWorld(), OtherActorStart, OtherActorEnd, FColor::Red, false, DeltaTime * 1.5, 0, 5);
            
//            Проверка пересечения траекторий по XY
            if(cross(GetActorLocation(), GetActorLocation() + ProjectileMovementComponent->Force, OtherActorStart, OtherActorStart + OtherActorVelocity)) {
//                UE_LOG(LogTemp, Warning, TEXT("Impact point: %s"), *ImpactPoint.ToString());
                    
                length = FVector::DistXY(GetActorLocation(), ImpactPoint);
                time = length / ProjectileMovementComponent->Force.Size2D();
                
                OtherActorLength = OtherActorVelocity.Size2D() * time;
//                UE_LOG(LogTemp, Warning, TEXT("OtherActorLength: %f"), OtherActorLength);
                
//                _OtherActor->SetActorLocation(OtherActorStart + OtherActorLength);
                
//                Узкая фаза проверки столкновений
                if(GetWorld()->OverlapMultiByChannel(ProjectileOverlapResult, GetActorLocation(), FQuat(0, 0, 0, 0), ECC_Visibility, FCollisionShape::MakeSphere(_CubeSize), ProjectileCollisionParams)) {
                    
            //        Проходимся по всем элементам, проникщих внутрь снаряда, и отсеиваем лишнее
                    for (int i = 0; i < ProjectileOverlapResult.Num(); i++) {
                        if(ProjectileOverlapResult[i].GetActor() != this) {
                            GEngine->AddOnScreenDebugMessage(-1, DeltaTime, FColor::Green, FString::Printf(TEXT("Collision detected!")));
                            
//                            IsHited = true;
                        }
                    }
                }
                
//                _OtherActor->SetActorLocation(OtherActorStart);
            }
        }
        
//        Проверка столкновений со статичными объектами
        else {
//            if(_OtherActor != GetOwner())
//                ProjectileReflection();
        }
    }
}

void AFPSProjectile::CalcVelocity(FVector& DeltaVelocity) {
    if(!CoordCalc && PastCoordCalc) {
        CurrCoord = _OtherActor->GetActorLocation();
        DeltaVelocity = CurrCoord - PastCoord;
        CoordCalc = true;
    }
    
    if(!PastCoordCalc) {
        PastCoord = _OtherActor->GetActorLocation();
        PastCoordCalc = true;
    }
}

bool AFPSProjectile::NarrowPhaseCollisionDetection(FVector Velocity, float Radius) {
    float Diametr = Radius * 2;
    
    if((Velocity.X <= Diametr) || (Velocity.Y <= Diametr) || (Velocity.Z <= Diametr))
        return true;
        
    return false;
}

void AFPSProjectile::ProjectileReflection() {
    // Не пробил
    if (0 < k && k <= 0.1) {
        UE_LOG(LogTemp, Error, TEXT("Don't Penetrate"));
    }
    
    // Проникнул и застрял
    if (0.11 < k && k <= 0.7) {
//        UE_LOG(LogTemp, Error, TEXT("Penetrate"));
        
        ProjectileMovementComponent->Force.Set(0, 0, 0);
        
        if( ! Called) {
//            PenetrationDepth = FVector::Dist(GetActorLocation(), _OtherActor->GetActorLocation());
            PenetrationDepth = GetHorizontalDistanceTo(_OtherActor);
            UE_LOG(LogTemp, Error, TEXT("PenetrationDepth: %f"), PenetrationDepth);
            Called = true;
        }
        
        
//        SetActorLocation(_OtherActor->GetActorLocation() + ((OtherActorVelocity / OtherActorVelocity.Size()) * PenetrationDepth));
        SetActorLocation(_OtherActor->GetActorLocation() + (_OtherActor->GetActorForwardVector() * PenetrationDepth));
    }
    
    // Рикошет
    if (0.3 < k && k <= 0.7) {
        if(AttackAngle >= 45)
            UE_LOG(LogTemp, Error, TEXT("Rebound"));
        Called = true;
    }
    
    // На вылет
    if (0.7 < k && k <= 1) {
        UE_LOG(LogTemp, Error, TEXT("Through"));
    }
}
