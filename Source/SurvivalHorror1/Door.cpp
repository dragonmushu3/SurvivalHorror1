// Mushu Damaschin. All Rights Reserved.


#include "Door.h"

// Sets default values
ADoor::ADoor()
{
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
	RootComponent = CreateDefaultSubobject<USceneComponent>("RootComponent");
	ConstraintComponent = CreateDefaultSubobject<UPhysicsConstraintComponent>("ConstraintComponent");
	InteractableComponent = CreateDefaultSubobject<UInteractableComponent>("InteractableComponent");

	RootComponent->SetMobility(EComponentMobility::Static);
	MeshComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	ConstraintComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();

	// Set up physics constraints
	if (ConstraintComponent)
	{
		// Cast RootComponent to UPrimitiveComponent
		UPrimitiveComponent* RootPrimitiveComponent = Cast<UPrimitiveComponent>(RootComponent);

		ConstraintComponent->SetConstrainedComponents(RootPrimitiveComponent, NAME_None, MeshComponent, NAME_None);
	}

	// Set up interactable settings
	InteractableComponent->InteractionText = "Open/Close";
	InteractableComponent->OnInteract.AddDynamic(this, &ADoor::ToggleDoor);
}

void ADoor::ToggleDoor()
{
    bIsOpen = !bIsOpen;
}