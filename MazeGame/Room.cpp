#include <iostream>
#include<windows.h>
#include "Room.h"
#include "ConsoleDrawer.h"
using namespace std;

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


void Room::Draw(int x, int y)
{
	int pixelX = x * RoomSize;
	int pixely = y * RoomSize;
	this->UpPartition->Draw(pixelX, pixely, RoomSize + 1, Side::up);

	this->LeftPartition->Draw(pixelX, pixely + 1, RoomSize - 1, Side::left);

	int downX = pixelX + RoomSize;
	this->RightPartition->Draw(downX, pixely + 1, RoomSize - 1, Side::right);

	int rightY = pixely + RoomSize;
	this->DownPartition->Draw(pixelX, rightY, RoomSize + 1, Side::down);


}

void Room::Draw()
{
	Draw(x, y);
}


int Room::GetIndexX()
{
	return this->x;
}

void Room::Draw(int x, int y, int indentationYAxis)
{
	int pixelX = x * RoomSize;
	int pixely = (y * RoomSize) + indentationYAxis;
	this->UpPartition->Draw(pixelX, pixely, RoomSize + 1, Side::up);

	this->LeftPartition->Draw(pixelX, pixely + 1, RoomSize - 1, Side::left);

	int downX = pixelX + RoomSize;
	this->RightPartition->Draw(downX, pixely + 1, RoomSize - 1, Side::right);

	int rightY = pixely + RoomSize;
	this->DownPartition->Draw(pixelX, rightY, RoomSize + 1, Side::down);

}

int Room::GetIndexY()
{
	return this->y;
}

int Room::GetRoomSize()
{
	return this->RoomSize;
}

IPartition* Room::GetLeftPartition()
{
	return this->LeftPartition;
}

IPartition* Room::GetRightPartition()
{
	return this->RightPartition;
}

IPartition* Room::GetUpPartition()
{
	return this->UpPartition;
}

IPartition* Room::GetDownPartition()
{
	return this->DownPartition;
}

