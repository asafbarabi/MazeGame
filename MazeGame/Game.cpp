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
	int indentationYAxis = numPlayers + 2;
	srand(time(NULL));
	Treasure* arrTreasure = new Treasure[numPlayers];
	//TODO sagi check if not the same index
	this->SetPlayerExternalRoomIndex(players, numPlayers);
	this->SetTreasureRoomIndex(arrTreasure,players, numPlayers);

	this->maze = new Maze(players, arrTreasure, numPlayers, ROOM_SIZE);
	this->maze->Draw(indentationYAxis);
	for (int i = 0; i < numPlayers; i++)
	{
		players[i].CurrentRoom = maze->Rooms[players->CurrentRoomIndex];
		players[i].Draw(players,arrTreasure, numPlayers, indentationYAxis);
	}
	//print treasures
	for (int i = 0; i < numPlayers; i++)
	{
		arrTreasure[i].Draw(ROOM_SIZE, indentationYAxis);
	}
	bool cycleOver = false;
	char selectedOption, selecteClue, selecteMove;
	//only for initalizaion
	bool stepSucceeded = false;
	IRoom* roomBehind;
  indentationYAxis += 40;
	int flightDistanceToTreasure;
	int notPlay = 0;
	int typeGame = 0;
	
	do {
		if (typeGame != 0 && typeGame != 1)
		{
			cout << "try again, only 0 or 1\n";
		}
		string gameType = "choose the type of the game, 0 is to play, 1 is to check the game(always draw the maze)\n";
		consoleDrawer.WriteString(0, indentationYAxis += 1, gameType);
		cin >> typeGame;
	} while (typeGame != 0 && typeGame != 1);
	while (!cycleOver) {
		for (int i = 0; i < numPlayers; i++)
		{
			if (players[i].CurrentRoom != NULL) {

				string playerTrun = "Now it is " + players[i].name + "'s turn:\nThis is your position:";
				consoleDrawer.WriteString(0, indentationYAxis += 2, playerTrun);

				players[i].CurrentRoom->Draw(0, 0, indentationYAxis += 2);
				players[i].DrawInSpecificRoom(players, i, indentationYAxis);

				string chooseMove = "\nInstructions:\nEnter s to stay in the same place\nPress c to get a clue\nPress m to move to an adjacent room\n";
				consoleDrawer.WriteString(0, indentationYAxis += ROOM_SIZE, chooseMove);
				do {
					//selectedOption = 'm';
					cin >> selectedOption;
					switch (selectedOption)
					{
						indentationYAxis += ROOM_SIZE;
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
								indentationYAxis += 2;
								break;
							}
							indentationYAxis += 1;
							if (players[i].CurrentRoom == NULL)
							{
								notPlay++;
							}
							else if (players[i].CheckIfWon(arrTreasure, numPlayers)) {
								cycleOver = true;
								players[i].totalScore += players[i].Score;
								string winner = "the winner is " + players[i].name + " his score for this game " + to_string(players[i].Score) + "\n"
									+ " the total score of every player:\n";
								consoleDrawer.WriteString(0, indentationYAxis += ROOM_SIZE, winner);
								for (int j = 0; j < numPlayers; j++)
								{
									if (i!=j)
									players[j].totalScore -= players[j].Steps;
									players[j].Steps = 0;
									players[j].Score = 0;
									cout << players[j].name + " Total Score " + to_string(players[j].totalScore);
								}
								indentationYAxis = indentationYAxis + 3 + numPlayers ;
								break;
							}
							if (!stepSucceeded)
								cout << "couldn't walk there, there is a wall please choose anotehr side\n";
							indentationYAxis += 2;
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
								cout << "the distance between you and the closet treasure is: " + to_string(flightDistanceToTreasure) + "\n";
								indentationYAxis += 5;
								break;
							default:
								cout << "invalid input! try again\n";
								indentationYAxis += 2;
								break;
							}
							indentationYAxis += 3;
						} while (selecteClue != 'k' && selecteClue != 'u' && selecteClue != 'd' && selecteClue != 'r' && selecteClue != 'l');
						break;
					case 's':
						indentationYAxis += 2;
						break;
					default:
						cout << "invalid input! try again\n";
						indentationYAxis += 2;
						break;
					}
					
					//consoleDrawer.WriteString(0, indentationYAxis++ , players[i].name + " has " + to_string(players[i].Steps) + " steps");
				} while (selectedOption != 's' && selectedOption != 'c' && selectedOption != 'm');
			}
			players[i].Steps += 1;
			if (typeGame == 1 && !cycleOver) {
				maze->Draw(indentationYAxis += 8);
				for (int i = 0; i < numPlayers; i++)
				{
					players[i].CurrentRoom = maze->Rooms[players->CurrentRoomIndex];
					players[i].Draw(players, arrTreasure, numPlayers, indentationYAxis);
				}
				//print treasures
				for (int i = 0; i < numPlayers; i++)
				{
					arrTreasure[i].Draw(ROOM_SIZE, indentationYAxis);
				}
				indentationYAxis += 40;
			}
		}
		if (numPlayers == notPlay)
		{
			string end = "no more moves, game ends\n the total score of every player:\n";
			consoleDrawer.WriteString(0, indentationYAxis += ROOM_SIZE, end);

			for (int j = 0; j < numPlayers; j++)
			{
				players[j].totalScore -= players[j].Steps;
				players[j].Steps = 0;
				players[j].Score = 0;
				cout << players[j].name + " Total Score " + to_string(players[j].totalScore);
			}
			indentationYAxis = indentationYAxis + 3 + numPlayers ;

			maze->Draw(indentationYAxis += 8);
			for (int i = 0; i < numPlayers; i++)
			{
				players[i].CurrentRoom = maze->Rooms[players->CurrentRoomIndex];
				players[i].Draw(players, arrTreasure, numPlayers, indentationYAxis);
			}
			//print treasures
			for (int i = 0; i < numPlayers; i++)
			{
				arrTreasure[i].Draw(ROOM_SIZE, indentationYAxis);
			}
			indentationYAxis += 45;
			cycleOver = true;
		}
	}
	maze->Draw(indentationYAxis += 8);
	for (int i = 0; i < numPlayers; i++)
	{
		players[i].CurrentRoom = maze->Rooms[players->CurrentRoomIndex];
		players[i].Draw(players, arrTreasure, numPlayers, indentationYAxis);
	}
	//print treasures
	for (int i = 0; i < numPlayers; i++)
	{
		arrTreasure[i].Draw(ROOM_SIZE, indentationYAxis);
	}
	indentationYAxis += 45;
	cycleOver = true;
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

void Game::SetTreasureRoomIndex(Treasure* arrTreasure,Player* players, int numPlayers)
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
			if(arrTreasure[i].index>10 && arrTreasure[i].index<14)
			{
				if (arrTreasure[i].index - 10 > 14 - arrTreasure[i].index)
					arrTreasure[i].index = 14;
				else
					arrTreasure[i].index = 10;
			}
				if(arrTreasure[i].index>15 && arrTreasure[i].index<19)
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
