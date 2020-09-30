#pragma once
#include "Player.h"
#include "Maze.h"
class Game
{
public:
	Player* player;
	Maze* maze;

	Game(int numPlayers = 1);
	~Game();
	void StartGame();
	void StartCycle(Player* players, int numPlayers);

private:
	int NumberOfRoomsInRow;
	int NumberOfRoomsInColumn;

	//return a random index of an external room for the player (external room = a room on the frame of the maze)
	void GetPlayerExternalRoomIndex(Player* playersRandomRoomIndex, int numPlayers);
	void GetTreasureRoomIndex(Treasure* arrTreasure, int numPlayers);
};

