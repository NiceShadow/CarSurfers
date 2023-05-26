#include "PlayerController_cpp.h"
#include "Blueprint/UserWidget.h"

void APlayerController_cpp::BeginPlay()
{
	Super::BeginPlay();
	
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

void APlayerController_cpp::IncrementVariable()
{
	CoinCounter++;
}

