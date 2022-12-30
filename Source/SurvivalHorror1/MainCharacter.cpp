// Mushu Damaschin. All Rights Reserved.


#include "MainCharacter.h"
#include "GameFramework/Actor.h"
#include "Camera/CameraComponent.h"
#include "Components/SceneComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/ArrowComponent.h"

// Sets default values
AMainCharacter::AMainCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Instantiating your class Components
	CameraOriginLocation = CreateDefaultSubobject<UArrowComponent>(TEXT("CameraOriginLocation"));
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));

	// Attaching the Components to the default character's Skeletal Mesh Component
	CameraOriginLocation->SetupAttachment(GetCapsuleComponent());
	CameraComp->SetupAttachment(GetCapsuleComponent());
}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("SwitchCamera", IE_Pressed, this, &AMainCharacter::SetCameraOriginLocation);
}

void AMainCharacter::SetCameraOriginLocation()
{
	CameraComp->SetRelativeLocation(CameraOriginLocation->GetRelativeLocation());
}