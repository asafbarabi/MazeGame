#pragma once
#include "Room.h"
#include "IPartition.h"
#include "Wall.h"
#include "Door.h"
#include <stdlib.h>
#include <time.h>
#include "Treasure.h"
#include "Player.h"

class Maze
{
public:
	Maze(Player* arrPlayers, Treasure* arrTreasure, int numPlayers, int roomSize);
	~Maze();
	Room* Rooms[25];
	void Draw(Player* players, Treasure* arrTreasure, int numPlayers);
	void Draw(int indentationYAxis, Player* players, Treasure* arrTreasure, int numPlayers);

private:
	IPartition* CreateRandomPartition(Side side);

};

