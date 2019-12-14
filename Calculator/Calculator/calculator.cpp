#include "calculator.h"

void Initialize(void)
{
	srand((unsigned int)time(NULL));
	system("mode con cols=60 lines=20 | title Calculator");

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

void PrintLine(int xpos, int ypos, int amount)
{
	MoveCursor(xpos, ypos);
	for (int i = 0; i < amount; i++)
		cout << "=";
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
	case 27:
		return ESC;
	default:
		break;
	}
}

void PrintTitle(float Seconds)
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

void PrintMode(void)
{
	PrintLine(0, 1, CONSOLECOLS);
	PrintLine(0, 18, CONSOLECOLS);

	MoveCursor(24, 3);
	cout << "<조작 안내>";
	MoveCursor(2, 4);
	cout << "방향키로 위/아래를 이동하고 엔터 키를 이용해 선택합니다.";

	int x = 5, y = 6;
	MoveCursor(x, y);
	cout << "1. Basic Calculation (기본 계산)";
	MoveCursor(x, y + 2);
	cout << "2. Advanced Calculation (고급 계산:삼각/지수/로그함수 포함)";
	MoveCursor(x, y + 4);
	cout << "3. Matrix (행렬 계산)";
	MoveCursor(x, y + 6);
	cout << "4. Base-N (진수 변환)";
	MoveCursor(x, y + 8);
	cout << "5. Quit (프로그램 종료)";
}

int SelectMode(void)
{
	int x = 7, y = 6;
	while (1)
	{
		int n = ReadKey();
		switch (n) {
		case KEY_UP:
		{
			if (y > 6)
			{
				MoveCursor(x - 3, y);
				cout << " ";
				MoveCursor(x - 3, y -= 2);
				cout << ">";
			}
		}
		break;
		case KEY_DOWN:
		{
			if (y < 14)
			{
				MoveCursor(x - 3, y);
				cout << " ";
				MoveCursor(x - 3, y += 2);
				cout << ">";
			}
		}
		break;
		case ESC:
		{
			if (y == 6)
				return BASICCALC;
			else if (y == 8)
				return ADVANCEDCALC;
			else if (y == 10)
				return MATRIX;
			else if (y == 12)
				return BASE_N;
			else if (y == 14)
				return QUIT;
		}
		break;
		}
	}
}

void Calc::ClearConsole(void)
{
	system("cls");
}

string Calc_basic::InputInfixExp(void)
{
	cout << "\n\n";
	cout << "중위표기법(Infix Notation)으로 작성된 식을 입력하세요. 연산자 생략은 불가능합니다.\n";
	cin >> InfixExpression;	//null pointer error, why?
	cout << "TEST";

	PostfixExpression = ConvertToPostfix(InfixExpression);
	return PostfixExpression;
}

string Calc_basic::ConvertToPostfix(string InfixExp)	//if parameter is const string --> Error C2440
{

	string::iterator itr_ind = InfixExp.begin();	//iterator only used in index
	string::iterator itr_str = InfixExp.begin();	//iterator only used in accessing
	//string::iterator end; -- isn't it useless?

	vector<char> stack;	//using vector as a stack!

	for (; itr_ind != InfixExp.end(); ++itr_ind)
	{
		//if stream value is not an operator -- pass
		if (Calc_basic::operators.find(*itr_ind) == string::npos)
		{
			PostfixExpression += *itr_ind;
			continue;
		}

		//operator processing
		PostfixExpression += " ";
		switch (*itr_str)
		{
		case'(':
			stack.push_back('(');
			break;
		case')':	//starting parenthetical calculation
			while (stack.back() != '(')
			{
				PostfixExpression += stack.back();
				PostfixExpression += " ";
				stack.pop_back();
			}
			stack.push_back(*itr_str);
			break;
		case'+':
		case'-':	//starting add/subtract calculation
			while (stack.size() != 0 && stack.back() != '(')
			{
				PostfixExpression += stack.back();
				PostfixExpression += " ";
				stack.pop_back();
			}
			stack.push_back(*itr_str);
			break;
		case'*':
		case'/':	//starting multiply/divide calculation
			while (stack.size() != 0 && stack.back() != '(' || stack.back() == '/')
			{
				PostfixExpression += stack.back();
				PostfixExpression += " ";
				stack.pop_back();
			}
			stack.push_back(*itr_str);
			break;
		case' ':
			break;
		default:
			//unknown error
			cout << "예상치 못한 에러가 발생했습니다. 프로그램을 종료합니다." << endl;
		}
		PostfixExpression += " ";
	}

	size_t stacksize = stack.size();
	for (size_t i = 0; i < stacksize; ++i)
	{
		PostfixExpression += " ";
		PostfixExpression += stack.back();
		stack.pop_back();
	}

	return PostfixExpression;
}

double Calc_basic::Calculate(const string PostFixExp)
{
	vector<double> stack;
	string str = "";
	stringstream temp(PostFixExp);

	while (!temp.eof())
	{
		temp >> str;

		if (operators.find(str) == string::npos)
		{
			double dtemp;
			stringstream(str) >> dtemp;
			stack.push_back(dtemp);
		}
		else
		{
			double d1, d2;
			d2 = stack.back();
			stack.pop_back();
			d1 = stack.back();
			stack.pop_back();

			switch (operators[operators.find(str)])
			{
			case '+':
				stack.push_back(d1 + d2);
				break;
			case '-':
				stack.push_back(d1 - d2);
				break;
			case '*':
				stack.push_back(d1 * d2);
				break;
			case '/':
				stack.push_back(d1 / d2);
				break;
			}
		}
	}
	return stack.back();
}