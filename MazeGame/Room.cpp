#include <iostream>
#include "Room.h"
using namespace std;

Room::Room(IPartition* upPartition, IPartition* downPartition, IPartition* rightPartition, IPartition* leftPartition, int roomSize)
{
	this->UpPartition = upPartition;
	this->DownPartition = downPartition;
	this->RightPartition = rightPartition;
	this->LeftPartition = leftPartition;
	this->RoomSize = roomSize;

}

//Default ctor with roomSize =5
Room::Room(IPartition* upPartition, IPartition* downPartition, IPartition* rightPartition, IPartition* leftPartition) :Room(upPartition, downPartition, rightPartition, leftPartition, 5)
{
}

void Room::Draw(Point* location)
{
	this->UpPartition->Draw(location, this->RoomSize);
	this->DownPartition->Draw(location, this->RoomSize);
	this->RightPartition->Draw(location, this->RoomSize);
	this->LeftPartition->Draw(location, this->RoomSize);
}

IPartition* Room::GetPartition(Side side)
{
	switch (side)
	{
	case Side::up:
		return this->UpPartition;
	case Side::down:
		return this->DownPartition;
		break;
	case Side::left:
		return this->LeftPartition;
		break;
	case Side::right:
		return this->RightPartition;
		break;
	default:
		break;
	}
}
