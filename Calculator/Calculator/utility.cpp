#include "utility.h"

Utility::Utility(int xpos, int ypos)
{
	xPos = xpos;
	yPos = ypos;
}
void Utility::SetPos(int xpos, int ypos)
{
	xPos = xpos;
	yPos = ypos;
}
void Utility::RefreshConsole(void)
{
	system("cls");	//erase everythinig in console
	for (int i = 0; i < CONSOLECOLS; i++)
	{
		PrintConsole(0, 1, '=');		//print upper line
		PrintConsole(0, 18, '=');	//print lower line
	}
}
void Utility::WaitforSec(double seconds)
{
	Sleep(1000 * seconds);
}
void Utility::PrintTitle(double seconds)
{
	MoveCursor(xPos, yPos);
	cout <<
		"  ________   __   _______  ____   ___ __________  ___ \n"
		" / ___/ _ | / /  / ___/ / / / /  / _ /_  __/ __ \\/ _ \\\n"
		"/ /__/ __ |/ /__/ /__/ /_/ / /__/ __ |/ / / /_/ / , _/\n"
		"\\___/_/ |_/____/\\___\/\____/____/_/ |_/_/  \\____/_/|_| \n" << endl;
	cout << "Introduction to Programming(2) Team Project\n19101279 조계진\n19101191 김경준" << endl;
	WaitforSec(seconds);
	RefreshConsole();
}
int Utility::InstantReadKey(void)
{
	int temp = _getch();

	switch (temp)
	{
	case KEY_UP:
		return KEY_UP;
	case KEY_DOWN:
		return KEY_DOWN;
	case KEY_LEFT:
		return KEY_LEFT;
	case KEY_RIGHT:
		return KEY_RIGHT;
	case SUBMIT:
		return SUBMIT;
	case ESC:
		return ESC;
	case A:
		return A;
	case B:
		return B;
	default:
		return temp;
		break;
	}
}
template <typename contents> void Utility::PrintConsole(contents)
{
	MoveCursor(xPos, yPos);
	cout << contents;		//print something
}
void Utility::PrintGuide(void)
{
	//not using virtual in here! "virtual" void Utility::PrintGuide(void)
	PrintConsole("방향키로 위/아래를 이동하고, 엔터 키로 선택하세요.");
}
void Utility::PrintMode(string setting)
{
	if (setting == "BASIC")
	{
		PrintConsole("1. 기본 계산(수식 입력)");
		SetPos(xPos, yPos + 2);
		PrintConsole("2. Matrix (행렬 계산)");
		SetPos(xPos, yPos + 4);
		PrintConsole("3. Base-N (진수 변환)");
		SetPos(xPos, yPos + 6);
		PrintConsole("4. Quit (프로그램 종료)");
	}
}
int Utility::SelectMode(string modeAt)
{
	int x_temp = xPos;
	int y_temp = yPos;	//copy value(to keep original value safe)

	int y_top;
	while (1)
	{
		int n = InstantReadKey();
		switch (n) {
		case KEY_UP:
		{
			if (y_temp > 6)
			{
				MoveCursor(x_temp - 3, y_temp);
				cout << " ";
				MoveCursor(x_temp - 3, y_temp -= 2);
				cout << ">";
			}
		}
		break;
		case KEY_DOWN:
		{
			if (y_temp < 14)
			{
				MoveCursor(x_temp - 3, y_temp);
				cout << " ";
				MoveCursor(x_temp - 3, y_temp += 2);
				cout << ">";
			}
		}
		break;
		case SUBMIT:
		{
			if (y_temp == 6)
				return CALCULATION;
			else if (y_temp == 8)
				return MATRIX;
			else if (y_temp == 10)
				return BASE_N;
			else if (y_temp == 12)
				return QUIT;
		}
		break;
		}
	}
}
void Utility::ExitCalc(void)
{
	PrintConsole(xPos, yPos, "프로그램을 종료합니다.");
	PrintTitle(1.5);
	exit(0);
}
void Utility::ExitCalc(string error)
{
	PrintConsole(xPos, yPos, error);
}