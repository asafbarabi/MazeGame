#pragma once
#include "IRoom.h"
#include "Partition.h"
#include "ConsoleDrawer.h"
#include <string>
class Player
{
public:
	IRoom* CurrentRoom;
	int Score;
	int Steps;
	string name;
	int startRoom;

	Player(string name=NULL);

	bool Step(Side side);
	unsigned int GetFlightDistanceToTreasure();
	bool GetContentOfNextRoom(Side side);
	void Draw(Player* arrPlayer,int playerNumber);

	



};

