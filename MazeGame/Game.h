#pragma once
#include "Player.h"
#include "Maze.h"
class Game
{
public:
	Player* player;
	Maze* maze;

	Game();
	void StartGame();

private:
	int NumberOfRoomsInRow;
	int NumberOfRoomsInColumn;

	//return a random index of an external room for the player (external room = a room on the frame of the maze)
	int GetPlayerExternalRoomIndex();
};

