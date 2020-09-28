#include <iostream>
#include "Room.h"
#include "Door.h"
#include "Wall.h"
using namespace std;

int main()
{
	system("color f5");
	Door upDoor(Side::up);
	Wall rightDoor(Side::right);
	Wall downWall(Side::down);
	Wall leftWall(Side::left);
	Room room(&upDoor, &downWall, &rightDoor, &leftWall);
	room.Draw(0,0);
	cout << "\n";
	system("pause");
	return 0;
}
