// Copyright Epic Games, Inc. All Rights Reserved.

#include "CarSurfersGameMode.h"
#include "CarSurfersCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACarSurfersGameMode::ACarSurfersGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
