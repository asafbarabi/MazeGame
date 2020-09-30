#include <iostream>
#include<windows.h>
#include "Room.h"
#include "ConsoleDrawer.h"
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

Room::~Room()
{
	delete UpPartition;
	delete DownPartition;
	delete RightPartition;
	delete LeftPartition;
}

//Default ctor with roomSize =ROOM_SIZE
Room::Room(IPartition* upPartition, IPartition* downPartition, IPartition* rightPartition, IPartition* leftPartition) :Room(upPartition, downPartition, rightPartition, leftPartition, ROOM_SIZE)
{
}

void Room::Draw(int x, int y)
{
	int pixelX = x * RoomSize;
	int pixely = y * RoomSize;
	this->UpPartition->Draw(pixelX, pixely, RoomSize + 1);

	this->LeftPartition->Draw(pixelX, pixely + 1, RoomSize - 1);

	int downX = pixelX + RoomSize;
	this->RightPartition->Draw(downX, pixely + 1, RoomSize - 1);

	int rightY = pixely + RoomSize;
	this->DownPartition->Draw(pixelX, rightY, RoomSize + 1);

	if (this->GetTreasure() > 0) {
		ConsoleDrawer* consoleDrawer;
		consoleDrawer = consoleDrawer->GetInstance();
		consoleDrawer->WriteString(pixelX + 2, pixely + 1, to_string(this->GetTreasure()));
	}
}

void Room::Draw()
{
	Draw(x, y);
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
		cout << "partition side not implemented";
	default:
		break;
	}
}

int Room::GetIndexX()
{
	return this->x;
}

int Room::GetIndexY()
{
	return this->y;
}

int Room::GetRoomSize()
{
	return this->RoomSize;
}

int Room::GetTreasure()
{
	return this->treasure;
}
