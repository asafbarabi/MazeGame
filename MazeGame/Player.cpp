#include "Player.h"

Player::Player()
{
	string name = "sagi";
	Score = 0;
	Steps = 0;
	this->name = name;
	int startRoom = 0;
}
bool Player::CheckIfWon(Treasure* arrTreasure, int numberOfTreasuers)
{
	for (int i = 0; i < numberOfTreasuers; i++)
	{
		if (arrTreasure[i].index == this->CurrentRoomIndex) {
			this->Score = arrTreasure[i].value - this->Steps;
			return true;
		}
	}
	return false;
}

bool Player::Step(Side side)
{
	IPartition* selectedPartition = GetPartition(side);
	if (selectedPartition->CanWalkThrough())
	{
		this->CurrentRoom = selectedPartition->GetRoomBehind();
		this->Steps++;
		return true;
	}
	else
		return false;
}

void Player::PeekToRoomBehind(Side side, int indentationYAxis)
{
	IRoom* roomBehind = nullptr;
	switch (side)
	{
	case up:
		roomBehind = this->CurrentRoom->GetUpPartition()->GetRoomBehind();
		break;
	case down:
		roomBehind = this->CurrentRoom->GetDownPartition()->GetRoomBehind();
		break;
	case Side::left:
		roomBehind = this->CurrentRoom->GetLeftPartition()->GetRoomBehind();
		break;
	case Side::right:
		roomBehind = this->CurrentRoom->GetLeftPartition()->GetRoomBehind();
		break;
	default:
		break;
	}
	if (roomBehind == nullptr) {
		cout << "the room you chose is outside the maze\n";
	}
	else {
		//add indentation to y axix
		roomBehind->Draw(0, 0, indentationYAxis);
	}
	Steps++;
}

unsigned int Player::GetFlightDistanceToTreasure(Treasure* arrTreasure, int numberOfTreasuers)
{
	int shortestlengthInRoomsFromTreasure = 1000;
	for (int i = 0; i < numberOfTreasuers; i++)
	{
		int playerIndexX = this->CurrentRoomIndex % 5;
		int playerIndexY = this->CurrentRoomIndex / 5;
		int treasureIndexX = arrTreasure[i].index % 5;
		int treasureIndexY = arrTreasure[i].index / 5;
		int lengthInRoomsFromTreasure = abs(treasureIndexX - playerIndexX) + abs(treasureIndexY - playerIndexY);
		if (lengthInRoomsFromTreasure < shortestlengthInRoomsFromTreasure)
			shortestlengthInRoomsFromTreasure = lengthInRoomsFromTreasure;
	}
	return shortestlengthInRoomsFromTreasure;
}

bool Player::GetContentOfNextRoom(Side side)
{
	IPartition* selectedPartition = GetPartition(side);
	if (selectedPartition->CanWalkThrough())
	{
		//this->CurrentRoom = selectedPartition->GetRoomBehind();
		this->Steps++;
		return true;
	}
	else
		return false;
}

void Player::Draw(Player* arrPlayers, int numberOfPlayers, int indentationYAxis)
{
	ConsoleDrawer* consoleDrawer;
	consoleDrawer = consoleDrawer->GetInstance();
	int indexX = this->CurrentRoom->GetIndexX();
	int indexY = this->CurrentRoom->GetIndexY();
	//I added +2 and +1 so it will be drawen inside a room and not beside it
	int addToX = 2;
	int addToY = 1;
	for (int i = 0; i < numberOfPlayers; i++)
	{
		if (this->CurrentRoom == arrPlayers[i].CurrentRoom)
		{
			addToY += 1;
		}

	}

	consoleDrawer->WriteString(indexX * this->CurrentRoom->GetRoomSize() + addToX, indentationYAxis + indexY * this->CurrentRoom->GetRoomSize() + addToY, this->name);
}

IPartition* Player::GetPartition(Side side)
{
	IPartition* selectedPartition;
	switch (side)
	{
	case up:
		selectedPartition = CurrentRoom->GetUpPartition();
		break;
	case down:
		selectedPartition = CurrentRoom->GetDownPartition();
		break;
	case Side::left:
		selectedPartition = CurrentRoom->GetLeftPartition();
		break;
	case Side::right:
		selectedPartition = CurrentRoom->GetRightPartition();
		break;
	default:
		//only for the compiler
		selectedPartition = CurrentRoom->GetRightPartition();
		break;
	}
	return selectedPartition;
}
