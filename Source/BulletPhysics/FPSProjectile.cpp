// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSProjectile.h"

// Sets default values
AFPSProjectile::AFPSProjectile() {
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    
    if(!RootComponent)
        RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("ProjectileSceneComponent"));
    
    if(!CollisionComponent) {
        // Use a sphere as a simple collision representation.
        CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
        
//        CollisionComponent->OnComponentHit.AddDynamic(this, &AFPSProjectile::OnHit);
//        CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &AFPSProjectile::OnOverlap);
        
//        Чтобы снаряд проходил внутрь объекта, нужно отключить коллизию
//        CollisionComponent->BodyInstance.SetCollisionProfileName(TEXT("OverlapAll"));
        SetActorEnableCollision(false);
        
//        Для отлова событий коллизий
        CollisionComponent->SetNotifyRigidBodyCollision(true);
        
        // Set the sphere's collision radius.
        CollisionComponent->InitSphereRadius(15.0f);
        // Set the root component to be the collision component.
        RootComponent = CollisionComponent;
    }
    
    // Use this component to drive this projectile's movement.
    if(!ProjectileMovementComponent)
        ProjectileMovementComponent = CreateDefaultSubobject<UBulletComponent>(TEXT("ProjectileMovementComponent"));
    
    if (!ProjectileMeshComponent) {
        ProjectileMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMeshComponent"));
        static ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh(TEXT("'/Game/Sphere.Sphere'"));
        if (Mesh.Succeeded())
            ProjectileMeshComponent->SetStaticMesh(Mesh.Object);

        static ConstructorHelpers::FObjectFinder<UMaterial>Material(TEXT("'/Game/SphereMaterial.SphereMaterial'"));
        if (Material.Succeeded())
            ProjectileMaterialInstance = UMaterialInstanceDynamic::Create(Material.Object, ProjectileMeshComponent);
        
        ProjectileMeshComponent->SetMaterial(0, ProjectileMaterialInstance);
        ProjectileMeshComponent->SetRelativeScale3D(FVector(0.09f, 0.09f, 0.09f));
        ProjectileMeshComponent->SetupAttachment(RootComponent);
    }
    
    // Delete the projectile after 3 seconds.
    InitialLifeSpan = 3.0f;
    
    projectileState = 0;
    
    CoordCalc = false;
    PastCoordCalc = false;
    
    Density = 0.1;
    AttackAngle = 0;
    
    _CubeSize = CollisionComponent->GetScaledSphereRadius() * 2;
}

// Called when the game starts or when spawned
void AFPSProjectile::BeginPlay() {
	Super::BeginPlay();
    
    // Event called when component hits something.
    CollisionComponent->OnComponentHit.AddDynamic(this, &AFPSProjectile::OnHit);
}

// Called every frame
void AFPSProjectile::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

    switch (projectileState) {
        case FLYING:
            SetActorLocation(GetActorLocation() + ProjectileMovementComponent->Force);
            BroadPhaseCollisionDetection(DeltaTime);
            break;
        case DONT_PENETRATE:
            UE_LOG(LogTemp, Error, TEXT("Force: %s"), *ProjectileMovementComponent->Force.ToString());
            SetActorLocation(GetActorLocation() + ProjectileMovementComponent->Force);
            break;
        case PENETRATE:
            //            (OtherActorVelocity / OtherActorVelocity.Size()) <-> _OtherActor->GetActorForwardVector()
            NewPos = (_OtherActor->GetActorLocation() + (_OtherActor->GetActorForwardVector() * (OtherActorRadius + CollisionComponent->GetScaledSphereRadius())));
            NewPos.X = NewPos.X - PenetrationDepth;
            SetActorLocation(NewPos);
            break;
        case REBOUND:
            
            break;
        case THROUGH:
            
            break;
        default:
            break;
    }
}

// Function that initializes the projectile's velocity in the shoot direction.
void AFPSProjectile::FireInDirection(const FVector& ShootDirection) {
    ProjectileMovementComponent->Velocity = ShootDirection;
}

// Function that is called when the projectile hits something.
void AFPSProjectile::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
    UE_LOG(LogTemp, Warning, TEXT("OnHit Name: %s"), *OtherActor->GetName());
//    UE_LOG(LogTemp, Warning, TEXT("Normal: %s"), *Hit.Normal.ToString());
//
//    if (OtherActor != this) {
//        if(OtherComponent->IsSimulatingPhysics()) {
//            AttackAngle = ProjectileMovementComponent->Force.CosineAngle2D(Hit.Normal);
//            UE_LOG(LogTemp, Warning, TEXT("Cos(AttackAngle): %f"), AttackAngle);
            
//            OtherComponent->AddImpulseAtLocation(ProjectileMovementComponent->Velocity, Hit.ImpactPoint);
//        }
//    }

//    Не уничтожаем объект, чтобы он продолжал находиться внутри объекта после столкновения
//    Destroy();
}

void AFPSProjectile::OnOverlap(class UPrimitiveComponent* Comp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    UE_LOG(LogTemp, Error, TEXT("OnOverlap Name: %s"), *OtherActor->GetName());

}

void AFPSProjectile::CollisionDetection() {
    // Домнажаем на Velocity чтобы отодвинуть точку старта только в направлении движ. снаряда. Иначе траектория будет проходить рядом, а не через снаряд;
    Start = GetActorLocation();
    End = Start + ProjectileMovementComponent->Force + (ProjectileMovementComponent->Velocity * CollisionComponent->GetScaledSphereRadius());
    DrawDebugLine(GetWorld(), Start, End, FColor::Yellow, false, GetWorld()->GetDeltaSeconds() * 1.5, 0, CollisionComponent->GetScaledSphereRadius());
    
    if(GetWorld()->LineTraceSingleByChannel(LineOutHit, Start, End, ECC_Visibility, LineCollisionParams)) {
        if(LineOutHit.GetActor() != this) {
            GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Yellow, FString::Printf(TEXT("You will hit: %s"), *LineOutHit.GetActor()->GetName()));
        }
    }
}

bool AFPSProjectile::Cross(FVector a, FVector c, FVector b, FVector d) {
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
            
//             Вычисления работают только для объектов, движущихся через физику (Velocity). При движении по сплайну нормально прочитать Velocity и нарисовать траекторию невозможно!
//             Velocity высчитывается только при вкл. симуляции физики!

            OtherActorStart = _OtherActor->GetActorLocation();
            OtherActorEnd = OtherActorStart + (OtherActorVelocity * 90);
            DrawDebugLine(GetWorld(), OtherActorStart, OtherActorEnd, FColor::Red, false, DeltaTime * 1.5, 0, 5);
            
//            Проверка пересечения траекторий по XY
            if(Cross(GetActorLocation(), GetActorLocation() + ProjectileMovementComponent->Force, OtherActorStart, OtherActorStart + OtherActorVelocity)) {
                length = FVector::DistXY(GetActorLocation(), ImpactPoint);
                time = length / ProjectileMovementComponent->Force.Size2D();
                OtherActorLength = OtherActorVelocity.Size2D() * time;
                
                NarrowPhaseCollisionDetection(false);
                
//                Если на старте скорость слишком большая, а расстояние слишком маленькое, то снаряд проскочит точку пересечения
//                и при подстановке расстояние будет прибавляться, отдаляя снаряд еще дальше - надо также отнимать расстояние!
                NarrowPhaseCollisionDetection(true);
                
//                Определяем реакцию снаряда на столкновение
                ProjectileReflection();
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

void AFPSProjectile::NarrowPhaseCollisionDetection(bool isReverse) {
    OtherActorEnd = ProjectileMovementComponent->Velocity * OtherActorLength;
    
    if(isReverse)
        OtherActorEnd *= -1;
        
    _OtherActor->SetActorLocation(OtherActorStart + OtherActorEnd);
    
    if(GetWorld()->OverlapMultiByChannel(ProjectileOverlapResult, GetActorLocation(), FQuat(0, 0, 0, 0), ECC_Visibility, FCollisionShape::MakeSphere(_CubeSize), ProjectileCollisionParams)) {
//        Проходимся по всем элементам, проникших внутрь снаряда, и отсеиваем лишнее
        for (int i = 0; i < ProjectileOverlapResult.Num(); i++) {
            if(ProjectileOverlapResult[i].GetActor() != this) {
                GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Green, FString::Printf(TEXT("Collision detected!")));
                
//                LineTrace для получения нормали
                CollisionDetection();
            }
        }
    }
}

void AFPSProjectile::ProjectileReflection() {
    // Не пробил
    if (0 < Density && Density < 0.11) {
        UE_LOG(LogTemp, Error, TEXT("Don't Penetrate"));
        ProjectileMovementComponent->Force.Set(0, 0, -ProjectileMovementComponent->Force.Z);
        projectileState = DONT_PENETRATE;
    }
    
    // Проникнул и застрял
    if (0.11 < Density && Density < 0.71) {
        ProjectileMovementComponent->Force.Set(0, 0, 0);
        
//            Рассчет процента текущ. коэфф. плотности к макс. значению
        Density_percents = Density / 0.7;
        UE_LOG(LogTemp, Error, TEXT("Density_percents: %0.f%%"), Density_percents * 100);
        
//            Рассчет макс. расст. проникновения снаряда внутрь объекта
        OtherActorRadius = _OtherActor->GetComponentsBoundingBox().GetExtent().X;
        MaxPenetrationDepth = 2 * OtherActorRadius;
        
//            Рассчет текущ. глубины проникновения в зависимости от коэфф. плотности
        PenetrationDepth = MaxPenetrationDepth * Density_percents;
        
        UE_LOG(LogTemp, Error, TEXT("MaxPenetrationDepth: %f"), MaxPenetrationDepth);
        UE_LOG(LogTemp, Error, TEXT("PenetrationDepth: %f"), PenetrationDepth);
        
        projectileState = PENETRATE;
    }
    
    // Рикошет
    if (0.3 < Density && Density < 0.71) {
        if(AttackAngle >= 45) {
            UE_LOG(LogTemp, Error, TEXT("Rebound"));
            projectileState = REBOUND;
        }
    }
    
    // На вылет
    if (0.7 < Density && Density < 1.1) {
        UE_LOG(LogTemp, Error, TEXT("Through"));
        projectileState = THROUGH;
    }
}
