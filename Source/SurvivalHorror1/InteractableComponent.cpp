// Mushu Damaschin. All Rights Reserved.


#include "InteractableComponent.h"

// Sets default values for this component's properties
UInteractableComponent::UInteractableComponent()
{
	
}


void UInteractableComponent::Interact()
{
	//Call the OnInteract event
	OnInteract.Broadcast();
}


void UInteractableComponent::OnPlayerInteract()
{
	Interact();
}