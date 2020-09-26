#include "Player.h"

Player::Player(IRoom* currentRoom)
{
	CurrentRoom = currentRoom;
	Score = 0;
	Steps = 0;
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
