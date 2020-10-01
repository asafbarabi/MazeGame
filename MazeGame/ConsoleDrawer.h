#pragma once
#include<windows.h> 
#include<iostream>
#include <string>
using namespace std;

class ConsoleDrawer
{
private:
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	COORD coord;
public:
	ConsoleDrawer();
	void WritePixel(int x, int y, char charToDraw);
	void WriteString(int x, int y, string word);
	int GetX();
	int GetY();
	void SetConsoleCurserCoordinate(int x, int y);

	//singleton
	static ConsoleDrawer* GetInstance();
	ConsoleDrawer(ConsoleDrawer const&) = delete;
	void operator=(ConsoleDrawer const&) = delete;


};

