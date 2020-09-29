#include "Player.h"

Player::Player(string name)
{
	Score = 0;
	Steps = 0;
	this->name = name;
}

bool Player::Step(Side side)
{
	IPartition* selectedPartition = CurrentRoom->GetPartition(side);
	if (selectedPartition->CanWalkThrough())
	{
		this->CurrentRoom = selectedPartition->GetRoomBehind();
		this->Steps++;
		return true;
	}
	else
		return false;
}

unsigned int Player::GetFlightDistanceToTreasure()
{
	return 0;
}

bool Player::GetContentOfNextRoom(Side side)
{
	IPartition* selectedPartition = CurrentRoom->GetPartition(side);
	if (selectedPartition->CanWalkThrough())
	{
		this->CurrentRoom = selectedPartition->GetRoomBehind();
		this->Steps++;
		return true;
	}
	else
		return false;
}

void Player::Draw(int playerNumber)
{
	ConsoleDrawer* consoleDrawer;
	consoleDrawer = consoleDrawer->GetInstance();
	int indexX = this->CurrentRoom->GetIndexX();
	int indexY = this->CurrentRoom->GetIndexY();
	//I added +2 and +1 so it will be drawen inside a room and not beside it
	consoleDrawer->WriteString(indexX * this->CurrentRoom->GetRoomSize() + 2, indexY * this->CurrentRoom->GetRoomSize() + 1, this->name);
}
