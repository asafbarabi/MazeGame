#include "ConsoleDrawer.h"

ConsoleDrawer::ConsoleDrawer()
{
}

void ConsoleDrawer::WritePixel(int x, int y, char charToDraw)
{
	this->coord.X = x;
	this->coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	cout << charToDraw;
}

void ConsoleDrawer::WriteString(int x, int y, string word)
{
	this->coord.X = x;
	this->coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	cout << word;
}

ConsoleDrawer* ConsoleDrawer::GetInstance()
{
	static ConsoleDrawer instance; // Guaranteed to be destroyed.
								  // Instantiated on first use.
	return &instance;
}
