#include "Game.h"
#include <time.h>


int ROOM_SIZE = 8;

Game::Game(int numPlayers)
{
	Player* players = new Player[numPlayers];
	for (int i = 0; i < numPlayers; i++)
	{
		//TODO change this to cin<<
		players[i].name = "sagi";
	}
	this->StartCycle(players, numPlayers);
}

Game::~Game()
{
	delete player;
	delete maze;
}

void Game::StartGame()
{
}

void Game::StartCycle(Player* players, int numPlayers)
{
	srand(time(NULL));
	Treasure* arrTreasure = new Treasure[numPlayers];
	//TODO sagi check if not the same index
	this->GetPlayerExternalRoomIndex(players, numPlayers);
	this->GetTreasureRoomIndex(arrTreasure, numPlayers);

	this->maze = new Maze(players, arrTreasure, numPlayers, ROOM_SIZE);
	this->maze->Draw();
	for (int i = 0; i < numPlayers; i++)
	{
		players[i].CurrentRoom = maze->Rooms[players->CurrentRoomIndex];
		players[i].Draw(players, i, 0);
	}
	//print treasures
	for (int i = 0; i < numPlayers; i++)
	{
		arrTreasure[i].Draw(ROOM_SIZE);
	}
	bool cycleOver = false;
	char selectedOption;
	//only for initalizaion
	bool stepSucceeded = false;
	IRoom* roomBehind;
	int indentationYAxis = 45;
	int flightDistanceToTreasure;
	while (!cycleOver) {
		for (int i = 0; i < numPlayers; i++)
		{
			cout << "Now it is" + players[i].name + "'s turn:\n This is your position:";
			players[i].CurrentRoom->Draw(0, 0, indentationYAxis += ROOM_SIZE);
			cout << "\nInstructions:\nEnter s to stay in the same place\nPress c to get a clue\nPress m to move to an adjacent room\n";
			do {
				//selectedOption = 'm';
				cin >> selectedOption;
				switch (selectedOption)
				{
					//move player
				case 'm':
					cout << "Enter u to move up\nEnter d to move down\nEnter r to move right\nEnter l to move left\n";
					do {
						cin >> selectedOption;
						//selectedOption = 'u';
						switch (selectedOption)
						{
						case 'u':
							stepSucceeded = players[i].Step(Side::up);
							break;
						case 'd':
							stepSucceeded = players[i].Step(Side::down);
							break;
						case 'r':
							stepSucceeded = players[i].Step(Side::right);
							break;
						case 'l':
							stepSucceeded = players[i].Step(Side::left);
							break;
						default:
							cout << "invalid input! try again\n";
							break;
						}
						if (players[i].CheckIfWon(arrTreasure, numPlayers)) {
							cycleOver = true;
							break;
						}
						if (!stepSucceeded)
							cout << "couldn't walk there, there is a wall please choose anotehr side\n";
					} while ((selectedOption != 'u' && selectedOption != 'd' && selectedOption != 'r' && selectedOption != 'l') || !stepSucceeded);
					break;
					//get a clue
				case 'c':
					cout << "Enter k to get the distance to the closest treasure\nEnter u to get a clue about the room that is above you\nEnter d to get a clue about the room that is blow you\nEnter r to get a clue about the room that is to the right of you\nEnter l to get a clue about the room that is to the left of you";
					cin >> selectedOption;
					do {
						switch (selectedOption)
						{
						case 'u':
							players[i].PeekToRoomBehind(Side::up, indentationYAxis += 12);
							break;
						case 'd':
							players[i].PeekToRoomBehind(Side::down, indentationYAxis += 12);
							break;
						case 'r':
							players[i].PeekToRoomBehind(Side::right, indentationYAxis += 12);
							break;
						case 'l':
							players[i].PeekToRoomBehind(Side::left, indentationYAxis += 12);
							break;
						case 'k':
							flightDistanceToTreasure = players[i].GetFlightDistanceToTreasure(arrTreasure, numPlayers);
							cout << "the distance between you and the closet treasure is:" + to_string(flightDistanceToTreasure) + " steps";
							break;
						default:
							cout << "invalid input! try again";
							break;
						}
					} while (selectedOption != 'k' && selectedOption != 'u' && selectedOption != 'd' && selectedOption != 'r' && selectedOption != 'l');
					break;
				case 's':
					break;
				default:
					cout << "invalid input";
					break;
				}
			} while (selectedOption != 's' && selectedOption != 'c' && selectedOption != 'm');
		}
	}
}

void Game::GetPlayerExternalRoomIndex(Player* playersRandomRoomIndex, int numPlayers)
{

	for (int i = 0; i < numPlayers; i++)
	{

		int roomIndexX;
		int roomIndexY;
		int randomX = rand() % 2;
		int randomY = rand() % 2;
		if (randomX == 1)
			roomIndexX = 4;
		else
			roomIndexX = 0;
		if (randomY == 1)
			roomIndexY = 4;
		else
			roomIndexY = 0;
		playersRandomRoomIndex[i].CurrentRoomIndex = (roomIndexY * 5) + roomIndexX;
	}
}

void Game::GetTreasureRoomIndex(Treasure* arrTreasure, int numPlayers)
{
	for (int i = 0; i < numPlayers; i++)
	{
		arrTreasure[i].index = rand() % 25;
		arrTreasure[i].value = rand() % 1000;
	}

}
