#include <iostream>
#include "Room.h"
#include "Door.h"
#include "Wall.h"
using namespace std;

void main() 
{
	Door upDoor(Side::up);
	Door rightDoor(Side::right);
	Wall downWall(Side::down);
	Wall leftWall(Side::left);
	Room room(&upDoor, &downWall, &rightDoor, &leftWall);
	room.Draw();
	system("pause");
}