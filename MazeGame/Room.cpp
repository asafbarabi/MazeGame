#include <iostream>
#include<windows.h>
#include "Room.h"
using namespace std;
int ROOM_SIZE = 8;

Room::Room(IPartition* upPartition, IPartition* downPartition, IPartition* rightPartition, IPartition* leftPartition, int roomSize)
{
	this->x = 0;
	this->y = 0;
	this->UpPartition = upPartition;
	this->DownPartition = downPartition;
	this->RightPartition = rightPartition;
	this->LeftPartition = leftPartition;
	this->RoomSize = roomSize;

}

//Default ctor with roomSize =ROOM_SIZE
Room::Room(IPartition* upPartition, IPartition* downPartition, IPartition* rightPartition, IPartition* leftPartition) :Room(upPartition, downPartition, rightPartition, leftPartition, ROOM_SIZE)
{
}

void Room::Draw(int x, int y)
{

	this->UpPartition->Draw(x, y, RoomSize + 1);

	this->LeftPartition->Draw(x, y + 1, RoomSize - 1);

	int downX = x + RoomSize;
	this->RightPartition->Draw(downX, y + 1, RoomSize - 1);

	int rightY = y + RoomSize;
	this->DownPartition->Draw(x, rightY, RoomSize + 1);
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
