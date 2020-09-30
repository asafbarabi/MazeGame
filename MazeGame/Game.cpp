#include "Game.h"
#include <time.h>
#include "Treasure.h"



Game::Game(int numPlayers)
{
	srand(time(NULL));
	Player* arrPlayers = new Player [numPlayers];
	Treasure* arrTreasure = new Treasure[numPlayers];
	this->GetPlayerExternalRoomIndex(arrPlayers, numPlayers);
	this->GettreasureRoomIndex(arrTreasure, numPlayers);
	
	this->maze = new Maze(arrPlayers, arrTreasure, numPlayers);
	this->maze->Draw();
	this->player = new Player("Sagi");
	for (int i = 0; i < numPlayers; i++)
	{
		cin >> arrPlayers[i].name;
		arrPlayers[i].CurrentRoom = maze->Rooms[arrPlayers->startRoom];
		arrPlayers[i].Draw(arrPlayers,i);
	}
}

Game::~Game()
{
	delete player;
	delete maze;
}

void Game::StartGame()
{
}

void Game::GetPlayerExternalRoomIndex(Player* playersRandomRoomIndex,int numPlayers)
{

	for (int i = 0; i < numPlayers; i++)
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
		playersRandomRoomIndex[i].startRoom = (roomIndexY * 5) + roomIndexX;
	}
}

	void Game::GettreasureRoomIndex(Treasure* arrTreasure, int numPlayers)
	{
		for (int i = 0; i < numPlayers; i++)
		{
			arrTreasure[i].index = rand() % 25;
			arrTreasure[i].value = rand() % 1000;
		}

	}
