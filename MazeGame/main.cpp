#include <iostream>
#include "Maze.h"
using namespace std;

int main()
{
	system("color f5");
	/*Door upDoor(Side::up);
	Wall rightDoor(Side::right);
	Wall downWall(Side::down);
	Door leftWall(Side::left);
	Room room(&upDoor, &downWall, &rightDoor, &leftWall);
	room.Draw(0,0);*/
	Maze a;
	a.Draw();
	cout << "\n";
	system("pause");
	return 0;
}
