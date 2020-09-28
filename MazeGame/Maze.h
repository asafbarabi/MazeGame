#pragma once
#include "Room.h"
#include "IPartition.h"
#include "Partition.h"
#include "Wall.h"
#include "Door.h"
#include <stdlib.h>
#include <time.h>
class Maze
{
public:
	Maze();
	Room* Rooms[25];
	void Draw();
private:
	IPartition* CreateRandomPartition(Side side);

};

