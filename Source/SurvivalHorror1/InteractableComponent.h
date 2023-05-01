// Mushu Damaschin. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InteractableComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInteractSignature);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInteractEvent);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SURVIVALHORROR1_API UInteractableComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	UInteractableComponent();

	UPROPERTY(EditAnywhere)
	FString InteractionText;

	UPROPERTY(BlueprintAssignable, Category = "Interaction")
	FOnInteractSignature OnInteract;

	void Interact();

private:
	UFUNCTION()
	void OnPlayerInteract();
};
