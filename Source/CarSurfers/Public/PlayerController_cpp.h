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

	UFUNCTION(BlueprintCallable, Category = "MyCategory")
	void IncrementVariable();
	
	virtual void BeginPlay() override;
};
