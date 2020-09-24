#include <iostream>
#include "Room.h"
using namespace std;


Room::Room(Partition* upPartition, Partition* downPartition, Partition* rightPartition, Partition* leftPartition)
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
