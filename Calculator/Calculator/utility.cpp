#include "utility.h"

void Utility::RefreshConsole(void)
{
	system("cls");	//erase everythinig in console
	for (int i = 0; i < CONSOLECOLS; i++)
	{
		PrintAt(0, 1, '=');		//print upper line
		PrintAt(0, 18, '=');	//print lower line
	}
}
void Utility::WaitforSec(double seconds)
{
	Sleep(1000 * seconds);
}
void Utility::PrintTitle(double seconds)
{
	MoveCursor(0, 3);
	cout <<
		"  ________   __   _______  ____   ___ __________  ___ \n"
		" / ___/ _ | / /  / ___/ / / / /  / _ /_  __/ __ \\/ _ \\\n"
		"/ /__/ __ |/ /__/ /__/ /_/ / /__/ __ |/ / / /_/ / , _/\n"
		"\\___/_/ |_/____/\\___\/\____/____/_/ |_/_/  \\____/_/|_| \n" << endl;
	cout << "Introduction to Programming(2) Team Project\n19101279 조계진\n19101191 김경준" << endl;
	WaitforSec(seconds);
	system("cls");
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
	case 1:
		return 1;
	default:
		return temp;
		break;
	}
}
template <typename contents> void Utility::PrintAt(int xpos, int ypos, contents)
{
	MoveCursor(xpos, ypos);
	cout << contents;		//print something
}
void Utility::PrintGuide(int xpos, int ypos)
{
	//not using virtual in here! "virtual" void Utility::PrintGuide(void)
	PrintAt(5, 5, "이 프로그램은 공학용 계산기를 구현한 것입니다.");
}
void Utility::PrintMode(void)
{
	PrintAt(5, 6, "1. Basic Calculation (기본 계산)");
	PrintAt(5, 8, "2. Advanced Calculation (고급 계산:삼각/지수/로그함수 포함)");
	PrintAt(5, 10, "3. Matrix (행렬 계산)");
	PrintAt(5, 12, "4. Base-N (진수 변환)");
	PrintAt(5, 14, "5. Quit (프로그램 종료)");
}