// Mushu Damaschin. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/ArrowComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Actor.h"
#include "Camera/CameraComponent.h"
#include "Components/SceneComponent.h"
#include "MainCharacter.generated.h"

UCLASS()
class SURVIVALHORROR1_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Arrow Component for the Camera Origin viewpoint location
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	//class UArrowComponent *CameraOriginLocation;

	// Camera Component
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UCameraComponent *CameraComp;

	// Sets The CameraComp's relative location to the CameraOriginLocation ArrowComponent
	//void SetCameraOriginLocation();


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
