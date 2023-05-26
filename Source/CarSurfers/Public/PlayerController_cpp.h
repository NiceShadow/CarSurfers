#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerController_cpp.generated.h"

UCLASS()
class CARSURFERS_API APlayerController_cpp : public APlayerController
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, Category = "UI")
	int32 CoinCounter;

	UFUNCTION(BlueprintCallable, Category = "Coin")
	void IncrementVariable();

	UFUNCTION(BlueprintPure, Category = "Player Character")
	float GetPlayerCharacterXLocation() const;
	
	UPROPERTY(BlueprintReadWrite, Category = "UI")
	int32 Score;

	UFUNCTION(BlueprintCallable, Category = "Level")
	void ResetLevel();
	
	virtual void BeginPlay() override;

	// Declare the timer function
	void TimerFunction();

	// Start the timer
	void StartTimer();

	// Stop the timer
	void StopTimer();
	
protected:

	FTimerHandle TimerHandle;
};
