#include "Coin.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "GameFramework/Actor.h"
#include "Kismet/KismetSystemLibrary.h"
#include "PlayerController_cpp.h"

ACoin::ACoin()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACoin::BeginPlay()
{
	Super::BeginPlay();
	
	CylinderMeshComponent = FindComponentByClass<UStaticMeshComponent>();
	RotatingMovementComponent = FindComponentByClass<URotatingMovementComponent>();

	OnActorBeginOverlap.AddDynamic(this, &ACoin::OnCoinOverlap);

	if (RotatingMovementComponent && CylinderMeshComponent)
	{
		RotatingMovementComponent->SetUpdatedComponent(CylinderMeshComponent);
	}
}

void ACoin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Get the player character
	ACharacter* PlayerCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	if (PlayerCharacter)
	{
		// Compare X values
		if (GetActorLocation().X > PlayerCharacter->GetActorLocation().X + 500)
		{
			// Destroy the actor
			Destroy();
		}
	}

}

void ACoin::OnCoinOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	// Check if the overlapping actor is the player
	if (OtherActor->ActorHasTag("Player"))
	{
		for (auto It = GetWorld()->GetPlayerControllerIterator(); It; ++It)
		{
			APlayerController_cpp* PlayerController = Cast<APlayerController_cpp>(*It);
			if (PlayerController)
			{
				// Call the IncrementVariable function in the Player Controller
				PlayerController->IncrementVariable();
				break;
			}
		}
		
		// Destroy the coin actor
		Destroy();
	}
}



