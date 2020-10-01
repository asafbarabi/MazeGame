#pragma once
#include "IRoom.h"
#include "Partition.h"
#include "ConsoleDrawer.h"
#include <string>
#include <math.h>
#include "Treasure.h"
class Player
{
public:
	IRoom* CurrentRoom;
	int Score, totalScore;
	int Steps;
	string name;
	int CurrentRoomIndex;

	Player();

	//also updating its score
	bool CheckIfWon(Treasure* arrTreasure, int numberOfTreasuers);
	bool Step(Side side);
	void PeekToRoomBehind(Side side, int indentationYAxis);
	unsigned int GetFlightDistanceToTreasure(Treasure* arrTreasure, int numberOfTreasuers);
	bool GetContentOfNextRoom(Side side);
	void Draw(Player* arrPlayer, Treasure* treasure, int playerNumber, int indentationYAxis);
	void DrawInSpecificRoom(int indentationYAxis);
private:
	IPartition* GetPartition(Side side);



};

