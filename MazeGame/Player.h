#pragma once
#include "IRoom.h"
#include "Partition.h"
class Player
{
public:
	IRoom* CurrentRoom;
	int Score;
	int Steps;

	Player(IRoom* currentRoom);

	bool Step(Side side);
	unsigned int GetFlightDistanceToTreasure();
	bool GetContentOfNextRoom(Side side);

	



};

