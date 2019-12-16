#include "calculator.h"

void Initialize(void)
{
	srand((unsigned int)time(NULL));
	system("mode con cols=70 lines=30 | title Calculator");

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);	//Get ConsoleHandle
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;	//false or 0 : Hide cursor
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}
void MoveCursor(int xpos, int ypos)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = xpos;
	pos.Y = ypos;
	SetConsoleCursorPosition(consoleHandle, pos);
}

void Calculator::PrintGuide(double seconds)
{

}
void Calculator::PrintModes(void)
{

}
int Calculator::SelectMode(void)
{
	return test;
}
void Calculator::Calculate(void)
{

}