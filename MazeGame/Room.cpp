#include <iostream>
#include "Room.h"
using namespace std;


Room::Room(IPartition* upPartition, IPartition* downPartition, IPartition* rightPartition, IPartition* leftPartition)
{
	this->UpPartition = upPartition;
	this->DownPartition = downPartition;
	this->RightPartition = rightPartition;
	this->LeftPartition = leftPartition;
}

void Room::Draw()
{
	this->UpPartition->Draw();
	this->DownPartition->Draw();
	this->RightPartition->Draw();
	this->LeftPartition->Draw();
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
