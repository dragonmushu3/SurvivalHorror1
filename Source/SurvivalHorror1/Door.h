// Mushu Damaschin. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"
#include "InteractableComponent.h"
#include "Door.generated.h"

UCLASS()
class SURVIVALHORROR1_API ADoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoor();

protected:
	// Called when the game starts or when spawned
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent *MeshComponent;
	UPROPERTY(EditAnywhere)
	UPhysicsConstraintComponent *ConstraintComponent;
	UPROPERTY(EditAnywhere)
	UInteractableComponent *InteractableComponent;

	virtual void BeginPlay() override;


private:
	bool bIsOpen;

	void ToggleDoor();
};
