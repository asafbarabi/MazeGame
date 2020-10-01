#include <iostream>
#include "Game.h"
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
	int numPlayers;
	cout << "Hi, How many players ? ";
	cin >> numPlayers;
	Game g(numPlayers);
	cout << "\n";
	system("pause");
	return 0;
}
