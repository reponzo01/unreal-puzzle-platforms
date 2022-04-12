// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGameMode.h"

void ALobbyGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	++NumberOfPlayers;
	UE_LOG(LogTemp, Warning, TEXT("New player! Num Players: %d"), NumberOfPlayers);
	if (NumberOfPlayers >= 3)
	{
		UWorld* World = GetWorld();
		if (!ensure(World != nullptr)) return;
		bUseSeamlessTravel = true;
		World->ServerTravel("/Game/PuzzlePlatforms/Maps/Game?listen");
	}
}

void ALobbyGameMode::Logout(AController* Exiting)
{
	Super::Logout(Exiting);

	--NumberOfPlayers;
	UE_LOG(LogTemp, Warning, TEXT("Player left! Num Players: %d"), NumberOfPlayers);
}
