#include "PlayerController_cpp.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"

void APlayerController_cpp::BeginPlay()
{
	Super::BeginPlay();

	StartTimer();
	//spawn the widget into the viewport
	
	FString WidgetPath = "/Game/Blueprints/UIWidget.UIWidget_C";
	UClass* WidgetClass = LoadClass<UUserWidget>(nullptr, *WidgetPath);
	if (WidgetClass)
	{
		UUserWidget* WidgetInstance = CreateWidget<UUserWidget>(this, WidgetClass);
		if (WidgetInstance)
		{
			WidgetInstance->AddToViewport();
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Failed to create UI widget instance from WidgetClass: %s"), *WidgetClass->GetName());
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to load UI widget class from WidgetPath: %s"), *WidgetPath);
	}
}

float APlayerController_cpp::GetPlayerCharacterXLocation() const
{
	ACharacter* PlayerCharacter = GetCharacter();
	if (PlayerCharacter)
	{
		FVector PlayerLocation = PlayerCharacter->GetActorLocation();
		return PlayerLocation.X;
	}

	return 0.0f;  // Default value if Player Character is not valid
}

void APlayerController_cpp::IncrementVariable()
{
	CoinCounter++;
}


void APlayerController_cpp::TimerFunction()
{
	Score = GetPlayerCharacterXLocation()/(-10);
}

void APlayerController_cpp::StartTimer()
{
	float TimerInterval = 0.1f;  // Timer interval in seconds
	bool bLoop = true;  // Whether the timer should loop

	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &APlayerController_cpp::TimerFunction, TimerInterval, bLoop);
}

void APlayerController_cpp::StopTimer()
{
	GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
}

void APlayerController_cpp::ResetLevel()
{
	FString LevelName = "MAP_MainScene";
	UGameplayStatics::OpenLevel(this, FName(*LevelName));
}

