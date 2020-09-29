#pragma once
#include<windows.h> 
#include<iostream>
#include <string>
using namespace std;

class ConsoleDrawer
{
private:
	COORD coord;
public:
	ConsoleDrawer();
	void WritePixel(int x, int y, char charToDraw);
	void WriteString(int x, int y, string word);


	//singleton
	static ConsoleDrawer* GetInstance();
	ConsoleDrawer(ConsoleDrawer const&) = delete;
	void operator=(ConsoleDrawer const&) = delete;


};

