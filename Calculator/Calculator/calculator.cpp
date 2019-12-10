#include "calculator.h"

using namespace std;

void Initialize()
{
	srand((unsigned int)time(NULL));
	system("mode con cols=60 lines=30 | title Calculator");

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);	//Get ConsoleHandle
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;	//false or 0 : Hide cursor
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}

void MoveCursor(int x, int y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}


int ReadKey(void)
{
	int temp = _getch();

	switch (temp)
	{
	case 72:
		return KEY_UP;
	case 80:
		return KEY_DOWN;
	case 75:
		return KEY_LEFT;
	case 77:
		return KEY_RIGHT;
	case 10:
		return SUBMIT;
	default:
		return 0;
		break;
	}
}

void ShowTitle(float Seconds)
{
	MoveCursor(0, 2);
	cout << endl;
	cout <<
		"  ________   __   _______  ____   ___ __________  ___ \n"
		" / ___/ _ | / /  / ___/ / / / /  / _ /_  __/ __ \\/ _ \\\n"
		"/ /__/ __ |/ /__/ /__/ /_/ / /__/ __ |/ / / /_/ / , _/\n"
		"\\___/_/ |_/____/\\___\/\____/____/_/ |_/_/  \\____/_/|_| \n" << endl;
	cout << "Introduction to Programming(2) 자율 팀 프로젝트 : 공학용 계산기 구현" << endl;
	int seconds = 1000 * Seconds;
	Sleep(seconds);	//convert millliseconds[ms] to sencods[s]
	system("cls");
}

int ShowMode(void)
{
	MoveCursor(0, 2);
	for (int i = 0; i < 60; i++)
		cout << "-";

	MoveCursor(3, 7);
	cout << ">";
	MoveCursor(4, 7);
	cout << "1. Calculate(기본적인 계산)";
	MoveCursor(4, 8);
	cout << "2. Complex(복소수 계산)";
	MoveCursor(4, 9);
	cout << "3. Base-N(진수 변환)";
	MoveCursor(4, 10);
	cout << "4. Matrix(행렬 연산)";

	return 0;
}

/*int SelectMenu(void)
{
	int x = 25, y = 12;
	while (1)
	{
		int n = ReadKey();
		switch (n) {
		case KEY_UP:
		{
			if (y > 12)
			{
				MoveCursor(x - 2, y);
				cout << " ";
				MoveCursor(x - 2, y -= 2);
				cout << ">";
			}
		}
		break;
		case KEY_DOWN:
		{
			if (y < 16)
			{
				MoveCursor(x - 2, y);
				cout << " ";
				MoveCursor(x - 2, y += 2);
				cout << ">";
			}
		}
		break;
		case SUBMIT:
		{
			if (y == 12)
				return GAME_START;
			else if (y == 14)
				return GAME_INFO;
			else if (y == 16)
				return GAME_QUIT;
		}
		break;
		}
	}
}
*/