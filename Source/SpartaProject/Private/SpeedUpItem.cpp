// Fill out your copyright notice in the Description page of Project Settings.


#include "SpeedUpItem.h"
#include "SpartaCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "TimerManager.h"


void ASpeedUpItem::BeginPlay()
{
	Super::BeginPlay();
	
}

ASpeedUpItem::ASpeedUpItem()
{
}

void ASpeedUpItem::ActivateItem(AActor* Activator)
{
	Super::ActivateItem(Activator);
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ASpeedUpItem::SpeedUp, 1.0f, true);
}

void ASpeedUpItem::SpeedUp()
{
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	if (PlayerController)
	{
		ASpartaCharacter* Player = Cast<ASpartaCharacter>(PlayerController->GetPawn());
		if (Player)
		{
			Player->GetCharacterMovement()->MaxWalkSpeed += 500.0f;
		}
	}
	GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ASpeedUpItem::SpeedDown, 5.0f, true);

	DestroyItem();
	
}

void ASpeedUpItem::SpeedDown()
{
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	if (PlayerController)
	{
		ASpartaCharacter* Player = Cast<ASpartaCharacter>(PlayerController->GetPawn());
		if (Player)
		{
			Player->GetCharacterMovement()->MaxWalkSpeed -= 500.0f;
		}
	}
}


