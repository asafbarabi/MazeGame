#include "Game.h"
#include <time.h>


int ROOM_SIZE = 8;
ConsoleDrawer consoleDrawer;


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
	this->SetPlayerExternalRoomIndex(players, numPlayers);
	this->SetTreasureRoomIndex(arrTreasure, players, numPlayers);
	this->maze = new Maze(players, arrTreasure, numPlayers, ROOM_SIZE);
	for (int i = 0; i < numPlayers; i++)
	{
		players[i].CurrentRoom = maze->Rooms[players->CurrentRoomIndex];
	}
	this->maze->Draw(players, arrTreasure, numPlayers);

	bool cycleOver = false;
	char selectedOption, selecteClue, selecteMove;
	//only for initalizaion
	bool stepSucceeded = false;
	IRoom* roomBehind;
	int flightDistanceToTreasure;
	int playersOutOfTheGame = 0;
	//0 to play, 1 to check the game(always draw the maze)
	int gameType = 0;


	cout << "choose the type of the game, 0 is to play, 1 is to check the game(always draw the maze)\n";
	cin >> gameType;
	while (gameType != 0 && gameType != 1) {
		cout << "invalid input please enter only 1 or 0\n";
		cin >> gameType;
	}

	while (!cycleOver) {
		//loop through every player
		for (int i = 0; i < numPlayers; i++)
		{
			//if player is out of the maze skip him
			if (players[i].CurrentRoom == NULL) {
				continue;
			}

			cout << "Now it is " + players[i].name + "'s turn:\nThis is your position:\n\n";

			//Draw player's room and player
			players[i].DrawInSpecificRoom(ConsoleDrawer::GetInstance()->GetY());
			players[i].CurrentRoom->Draw(0, 0, ConsoleDrawer::GetInstance()->GetY());


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
						cin >> selecteMove;
						//selectedOption = 'u';
						switch (selecteMove)
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

						//check if the player is out of the maze
						if (players[i].CurrentRoom == NULL) {
							playersOutOfTheGame++;
							//check if need to end the game because all the players lost
							if (playersOutOfTheGame == numPlayers) {
								cycleOver = true;
								break;
							}
						}

						//check if player won
						else if (players[i].CheckIfWon(arrTreasure, numPlayers)) {
							cycleOver = true;
							cout << "the winner is " + players[i].name + " his score for this game " + to_string(players[i].Score) + "\n";
							break;
						}
						if (!stepSucceeded)
							cout << "couldn't walk there, there is a wall please choose anotehr side\n";
					} while ((selecteMove != 'u' && selecteMove != 'd' && selecteMove != 'r' && selecteMove != 'l') || !stepSucceeded);
					break;
					//get a clue
				case 'c':
					cout << "Enter k to get the distance to the closest treasure\nEnter u to get a clue about the room that is above you\nEnter d to get a clue about the room that is blow you\nEnter r to get a clue about the room that is to the right of you\nEnter l to get a clue about the room that is to the left of you\n";
					cin >> selecteClue;
					do {

						switch (selecteClue)
						{
						case 'u':
							players[i].PeekToRoomBehind(Side::up, ConsoleDrawer::GetInstance()->GetY());
							break;
						case 'd':
							players[i].PeekToRoomBehind(Side::down, ConsoleDrawer::GetInstance()->GetY());
							break;
						case 'r':
							players[i].PeekToRoomBehind(Side::right, ConsoleDrawer::GetInstance()->GetY());
							break;
						case 'l':
							players[i].PeekToRoomBehind(Side::left, ConsoleDrawer::GetInstance()->GetY());
							break;
						case 'k':
							flightDistanceToTreasure = players[i].GetFlightDistanceToTreasure(arrTreasure, numPlayers);
							cout << "the distance between you and the closet treasure is: " + to_string(flightDistanceToTreasure) + "\n";
							break;
						default:
							cout << "invalid input! try again\n";
							break;
						}
					} while (selecteClue != 'k' && selecteClue != 'u' && selecteClue != 'd' && selecteClue != 'r' && selecteClue != 'l');
					break;
				case 's':
					break;
				default:
					cout << "invalid input! try again\n";
					break;
				}

			} while (selectedOption != 's' && selectedOption != 'c' && selectedOption != 'm');

			if (gameType == 1 && !cycleOver) {
				maze->Draw(players, arrTreasure, numPlayers);
			}
		}
	}
	maze->Draw(players, arrTreasure, numPlayers);

	//if no one won the game
	if (numPlayers == playersOutOfTheGame)
	{
		cout << "no more moves, game ends\n the total score of every player:\n";

		for (int j = 0; j < numPlayers; j++)
		{
			players[j].totalScore -= players[j].Steps;
			players[j].Steps = 0;
			players[j].Score = 0;
			cout << players[j].name + " Total Score " + to_string(players[j].totalScore);
		}
	}
	//if somebody won
	else 
	{
		for (int i = 0; i < numPlayers; i++)
		{
			if (players[i].Score > 0) {
				players[i].totalScore += players[i].Score - players[i].Steps;
			}
			else
				players[i].totalScore -= players[i].Steps;

			players[i].Steps = 0;
			players[i].Score = 0;
			cout << players[i].name + " Total Score " + to_string(players[i].totalScore);


		}
	}
}

void Game::SetPlayerExternalRoomIndex(Player* playersRandomRoomIndex, int numPlayers)
{

	for (int i = 0; i < numPlayers; i++)
	{
		srand(time(NULL));


		playersRandomRoomIndex[i].CurrentRoomIndex = rand() % 25;
		if (playersRandomRoomIndex[i].CurrentRoomIndex > 5 && playersRandomRoomIndex[i].CurrentRoomIndex < 9)
		{
			if (playersRandomRoomIndex[i].CurrentRoomIndex - 5 > 9 - playersRandomRoomIndex[i].CurrentRoomIndex)
				playersRandomRoomIndex[i].CurrentRoomIndex = 9;
			else
				playersRandomRoomIndex[i].CurrentRoomIndex = 5;
		}
		if (playersRandomRoomIndex[i].CurrentRoomIndex > 10 && playersRandomRoomIndex[i].CurrentRoomIndex < 14)
		{
			if (playersRandomRoomIndex[i].CurrentRoomIndex - 10 > 14 - playersRandomRoomIndex[i].CurrentRoomIndex)
				playersRandomRoomIndex[i].CurrentRoomIndex = 14;
			else
				playersRandomRoomIndex[i].CurrentRoomIndex = 10;
		}
		if (playersRandomRoomIndex[i].CurrentRoomIndex > 15 && playersRandomRoomIndex[i].CurrentRoomIndex < 19)
		{
			if (playersRandomRoomIndex[i].CurrentRoomIndex - 15 > 19 - playersRandomRoomIndex[i].CurrentRoomIndex)
				playersRandomRoomIndex[i].CurrentRoomIndex = 19;
			else
				playersRandomRoomIndex[i].CurrentRoomIndex = 15;
		}


	}
}

void Game::SetTreasureRoomIndex(Treasure* arrTreasure, Player* players, int numPlayers)
{
	for (int i = 0; i < numPlayers; i++)
	{
		arrTreasure[i].index = rand() % 25;
		if (arrTreasure[i].index > 5 && arrTreasure[i].index < 9)
		{
			if (arrTreasure[i].index - 5 > 9 - arrTreasure[i].index)
				arrTreasure[i].index = 9;
			else
				arrTreasure[i].index = 5;
		}
		if (arrTreasure[i].index > 10 && arrTreasure[i].index < 14)
		{
			if (arrTreasure[i].index - 10 > 14 - arrTreasure[i].index)
				arrTreasure[i].index = 14;
			else
				arrTreasure[i].index = 10;
		}
		if (arrTreasure[i].index > 15 && arrTreasure[i].index < 19)
		{
			if (arrTreasure[i].index - 15 > 19 - arrTreasure[i].index)
				arrTreasure[i].index = 19;
			else
				arrTreasure[i].index = 15;
		}
		arrTreasure[i].value = rand() % 1000;
		for (int j = 0; j < numPlayers; j++)
		{
			if (players[j].CurrentRoomIndex == arrTreasure[i].index)
			{
				i--;
				break;
			}
			if (i != j && arrTreasure[i].index == arrTreasure[j].index)
			{
				i--;
				break;
			}
		}

	}

}
