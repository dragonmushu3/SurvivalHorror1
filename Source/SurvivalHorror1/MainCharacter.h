// Mushu Damaschin. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
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

	// Arrow Component for the Camera shoulder viewpoint location
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	class UArrowComponent *CameraRShoulderLocation;

	// Arrow Component for the Camera Origin viewpoint location
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	class UArrowComponent *CameraOriginLocation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	class UCameraComponent* CameraComp;

	// Sets the CameraComp's relative location to CameraRShoulderLocation ArrowComponent.
	void SetCameraShoulderLocation();

	// Sets The CameraComp's relative location to the CameraOriginLocation arrow component
	void SetCameraOriginLocation();


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
