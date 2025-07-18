// Fill out your copyright notice in the Description page of Project Settings.


#include "SpeedUpItem.h"

#include <ThirdParty/ShaderConductor/ShaderConductor/External/DirectXShaderCompiler/include/dxc/DXIL/DxilConstants.h>

#include "SpartaCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "TimerManager.h"
#include "Components/SphereComponent.h"

ASpeedUpItem::ASpeedUpItem() : ItemSpeedMultiplier(10.0f)
{
}

void ASpeedUpItem::BeginPlay()
{
	Super::BeginPlay();
	
}



void ASpeedUpItem::ActivateItem(AActor* Activator)
{
	Super::ActivateItem(Activator);
	GetWorld()->GetTimerManager().SetTimer(ActiveItemTimerHandle, this, &ASpeedUpItem::SpeedUp, 0.2f, false);
}

void ASpeedUpItem::SpeedUp()
{
	GetWorld()->GetTimerManager().ClearTimer(SpeedUpItemTimerHandle);
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	if (PlayerController)
	{
		ASpartaCharacter* Player = Cast<ASpartaCharacter>(PlayerController->GetPawn());
		if (Player)
		{
			UE_LOG(LogTemp, Warning, TEXT("Speed Up Item Activated"));
			Player->SpeedMultiplier += ItemSpeedMultiplier;
			Player->GetCharacterMovement()->MaxWalkSpeed = Player->NormalSpeed * Player->SpeedMultiplier;
		}
	}
	GetWorld()->GetTimerManager().SetTimer(SpeedUpItemTimerHandle, this, &ASpeedUpItem::SpeedDown, 3.0f, false);

	//SetActorEnableCollision(false);
	//StaticMesh->SetVisibility(false);
	SetActorHiddenInGame(true);
	
}

void ASpeedUpItem::SpeedDown()
{
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	if (PlayerController)
	{
		ASpartaCharacter* Player = Cast<ASpartaCharacter>(PlayerController->GetPawn());
		if (Player)
		{
			UE_LOG(LogTemp, Warning, TEXT("Speed Down Item Activated"));
			Player->SpeedMultiplier -= ItemSpeedMultiplier;
			Player->GetCharacterMovement()->MaxWalkSpeed = Player->NormalSpeed * Player->SpeedMultiplier;
		}
	}
	DestroyItem();
}


