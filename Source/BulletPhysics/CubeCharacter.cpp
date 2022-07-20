// Fill out your copyright notice in the Description page of Project Settings.


#include "CubeCharacter.h"

// Sets default values
ACubeCharacter::ACubeCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    
//    VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
//    VisualMesh->SetupAttachment(RootComponent);
//
//    static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));
//
//    if (CubeVisualAsset.Succeeded())
//    {
//        VisualMesh->SetStaticMesh(CubeVisualAsset.Object);
//        VisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
//    }
}

// Called when the game starts or when spawned
void ACubeCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACubeCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACubeCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

    // Set up "movement" bindings.
    PlayerInputComponent->BindAxis("MoveForwardByArrow", this, &ACubeCharacter::MoveForwardByArrow);
    PlayerInputComponent->BindAxis("MoveRightByArrow", this, &ACubeCharacter::MoveRightByArrow);
}

void ACubeCharacter::MoveForwardByArrow(float Value)
{
    UE_LOG(LogTemp, Warning, TEXT("MoveForwardByArrow"));
    // Find out which way is "forward" and record that the player wants to move that way.
    FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
    AddMovementInput(Direction, Value);
}

void ACubeCharacter::MoveRightByArrow(float Value)
{
    // Find out which way is "right" and record that the player wants to move that way.
    FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
    AddMovementInput(Direction, Value);
}
