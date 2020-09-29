#include "Game.h"
#include <time.h>



Game::Game()
{
	srand(time(NULL));
	int playerRandomRoomIndex = this->GetPlayerExternalRoomIndex();
	int treasureRandomRoomIndex = rand() % 25;
	this->maze = new Maze(playerRandomRoomIndex, treasureRandomRoomIndex);
	this->maze->Draw();
	this->player = new Player("Sagi");
	this->player->CurrentRoom = this->maze->Rooms[playerRandomRoomIndex];
	this->player->Draw(1);
}

void Game::StartGame()
{
}

int Game::GetPlayerExternalRoomIndex()
{
	int roomIndexX;
	int roomIndexY;
	int randomX = rand() % 2;
	int randomY = rand() % 2;
	if (randomX == 1)
		roomIndexX = 4;
	else
		roomIndexX = 0;
	if (randomY == 1)
		roomIndexY = 4;
	else
		roomIndexY = 0;
	return (roomIndexY * 5) + roomIndexX;
}
