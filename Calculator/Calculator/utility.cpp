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
	MoveCursor(xPos, yPos);
}
void Utility::RefreshConsole(void)
{
	system("cls");	//erase everythinig in console
	SetPos(0, 0 + 3);
	for (int i = 0; i < CONSOLECOLS; i++)
		cout << "=";	//print upper line
	SetPos(0, CONSOLEROWS - 3);
	for (int i = 0; i < CONSOLECOLS; i++)
		cout << "=";	//print lower line
	//reason why divide two for loop -- better performance(using one loop is slow)
	SetPos(xPos, yPos);
}
void Utility::WaitforSec(double seconds)
{
	Sleep(1000 * seconds);
}
void Utility::PrintTitle(void)
{
	cout <<
		"  ________   __   _______  ____   ___ __________  ___ \n"
		" / ___/ _ | / /  / ___/ / / / /  / _ /_  __/ __ \\/ _ \\\n"
		"/ /__/ __ |/ /__/ /__/ /_/ / /__/ __ |/ / / /_/ / , _/\n"
		"\\___/_/ |_/____/\\___\/\____/____/_/ |_/_/  \\____/_/|_| \n" << endl;
	cout << "Introduction to Programming(2) Team Project\n19101279 조계진\n19101191 김경준" << endl;
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
void Utility::PrintConsole(string contents)
{
	cout << contents;
}
void Utility::PrintConsole(double value)
{
	cout << value;
}
void Utility::PrintConsole(char ch)
{
	cout << ch;
}
void Utility::PrintGuide(string setting)
{
	if (setting == "BASIC")
	{
		//not using virtual in here! "virtual" void Utility::PrintGuide(void)
		PrintConsole("안내 : 방향키로 위/아래를 이동하고, 엔터 키로 선택하세요.");
	}
	else if (setting == "ARITHMETIC")
	{
		PrintConsole("안내 : 중위 입력 형태의 식을 입력하세요.");
	}
}
void Utility::PrintModes(string setting)
{
	if (setting == "BASIC")
	{
		SetPos(xPos, yPos);
		PrintConsole("1. 기본 계산(수식 입력)");
		SetPos(xPos, yPos + 3);
		PrintConsole("2. Matrix (행렬 계산)");
		SetPos(xPos, yPos + 3);
		PrintConsole("3. Base-N (진수 변환)");
		SetPos(xPos, yPos + 3);
		PrintConsole("4. Quit (프로그램 종료)");
		SetPos(xPos, yPos - 9);	//subtract increased value -- to get initial yPos
	}
	else if (setting == "MATRIX")
	{
		SetPos(xPos, yPos);
		PrintConsole("1. 행렬 정의");
		SetPos(xPos, yPos + 3);
		PrintConsole("2. 행렬 수정");
		SetPos(xPos, yPos + 3);
		PrintConsole("3. 행렬 연산");
		SetPos(xPos, yPos - 6);
	}
	else if (setting == "MATRIX_CALCULATION")
	{
		SetPos(xPos, yPos);
		PrintConsole("1. 행렬 덧셈");
		SetPos(xPos, yPos + 3);
		PrintConsole("2. 스칼라 곱");
		SetPos(xPos, yPos + 3);
		PrintConsole("3. 전치");
		SetPos(xPos, yPos + 3);
		PrintConsole("4. 행렬 곱셈");
		SetPos(xPos, yPos + 3);
		PrintConsole("5. 역행렬 구하기");
		SetPos(xPos, yPos - 12);
	}
}
int Utility::SelectMode(string setting)
{
	int x_temp = xPos;
	int y_temp = yPos;	//copy value(to keep original value safe)
	if (setting == "BASIC")
	{
		int y_bottom = yPos;
		int y_top = yPos + 9;
		while (1)
		{
			int n = InstantReadKey();
			switch (n) {
			case KEY_UP:
			{
				if (y_temp > y_bottom)
				{
					MoveCursor(x_temp - 3, y_temp);
					cout << " ";
					MoveCursor(x_temp - 3, y_temp -= 3);
					cout << ">";
				}
			}
			break;
			case KEY_DOWN:
			{
				if (y_temp < y_top)
				{
					MoveCursor(x_temp - 3, y_temp);
					cout << " ";
					MoveCursor(x_temp - 3, y_temp += 3);
					cout << ">";
				}
			}
			break;
			case SUBMIT:
			{
				if (y_temp == yPos)
					return ARITHMETIC;
				else if (y_temp == yPos + 3)
					return MATRIX;
				else if (y_temp == yPos + 6)
					return BASE_N;
				else if (y_temp == yPos + 9)
					return QUIT;
			}
			break;
			}
		}
	}
	else if (setting == "MATRIX")
	{
		int y_bottom = yPos;
		int y_top = yPos + 4;
		while (1)
		{
			int n = InstantReadKey();
			switch (n) {
			case KEY_UP:
			{
				if (y_temp > y_bottom)
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
				if (y_temp < y_top)
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
					return DEFINEMATRIX;
				else if (y_temp == 8)
					return EDITMATRIX;
				else if (y_temp == 10)
					return CALCULATEMATRIX;
			}
			break;
			}
		}
	}
	else if (setting == "MATRIX_CALCULATION")
	{

		int y_bottom = yPos;
		int y_top = yPos + 8;
		while (1)
		{
			int n = InstantReadKey();
			switch (n) {
			case KEY_UP:
			{
				if (y_temp > y_bottom)
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
				if (y_temp < y_top)
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
					return ARITHMETIC;
				else if (y_temp == 8)
					return MATRIX;
				else if (y_temp == 10)
					return BASE_N;
				else if (y_temp == 12)
					return QUIT;
				else if (y_temp == 14)
					return QUIT;
			}
			break;
			}
		}
	}
}
void Utility::ExitCalc(void)
{
	RefreshConsole();
	SetPos(7, 10);
	PrintConsole("프로그램을 종료합니다.");
	WaitforSec(1.5);
	system("cls");
	SetPos(0, 0);
	PrintTitle();
	WaitforSec(1.5);
	exit(0);
}
void Utility::ExitCalc(string error)
{
	RefreshConsole();
	SetPos(7, 10);
	PrintConsole(error + "프로그램을 종료합니다.");
	WaitforSec(1.5);
	system("cls");
	SetPos(0, 0);
	PrintTitle();
	WaitforSec(1.5);
	exit(0);
}