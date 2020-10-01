#include "ConsoleDrawer.h"

ConsoleDrawer::ConsoleDrawer()
{
}

void ConsoleDrawer::WritePixel(int x, int y, char charToDraw)
{
	SetConsoleCurserCoordinate(x, y);
	cout << charToDraw;
}

void ConsoleDrawer::WriteString(int x, int y, string word)
{
	SetConsoleCurserCoordinate(x, y);
	cout << word;
}

int ConsoleDrawer::GetX()
{
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbiInfo);
	return csbiInfo.dwCursorPosition.X;
}

int ConsoleDrawer::GetY()
{
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbiInfo);
	return csbiInfo.dwCursorPosition.Y;
}

void ConsoleDrawer::SetConsoleCurserCoordinate(int x, int y)
{
	this->coord.X = x;
	this->coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

ConsoleDrawer* ConsoleDrawer::GetInstance()
{
	static ConsoleDrawer instance; // Guaranteed to be destroyed.
								  // Instantiated on first use.
	return &instance;
}
