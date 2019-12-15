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

void Calc_Util::ClearConsole(void)
{
	system("cls");
}
void Calc_Util::PrintTitle(double seconds)
{
	MoveCursor(0, 3);
	cout <<
		"  ________   __   _______  ____   ___ __________  ___ \n"
		" / ___/ _ | / /  / ___/ / / / /  / _ /_  __/ __ \\/ _ \\\n"
		"/ /__/ __ |/ /__/ /__/ /_/ / /__/ __ |/ / / /_/ / , _/\n"
		"\\___/_/ |_/____/\\___\/\____/____/_/ |_/_/  \\____/_/|_| \n" << endl;
	cout << "Introduction to Programming(2) Team Project\n19101279 조계진\n19101191 김경준" << endl;
	Delay(seconds);
	system("cls");
}
void Calc_Util::PrintGuide(int xpos, int ypos)
{
	PrintLine(0, 1, CONSOLECOLS);
	PrintLine(0, 18, CONSOLECOLS);
	MoveCursor(xpos, ypos);
	cout <<
		"<식 입력 안내>\n"
		"   중위표기법(Infix Notation)으로 작성된 식을 입력하세요.\n"
		"   연산자 생략은 불가능합니다.\n";
}
void Calc_Util::PrintAt(int xpos, int ypos, string contents)
{
	MoveCursor(xpos, ypos);
	cout << contents;
}
void Calc_Util::PrintAt(int xpos, int ypos, double db)
{
	MoveCursor(xpos, ypos);
	cout << db;
}
void Calc_Util::PrintLine(int xpos, int ypos, int amount)
{
	MoveCursor(xpos, ypos);
	for (int i = 0; i < amount; i++)
		cout << "=";
}
void Calc_Util::PrintMode(void)
{
	PrintLine(0, 1, CONSOLECOLS);
	PrintLine(0, 18, CONSOLECOLS);

	PrintAt(2, 4, "방향키로 위/아래를 이동하고 엔터 키를 이용해 선택합니다.");
	PrintAt(5, 6, "1. Basic Calculation (기본 계산)");
	PrintAt(5, 8, "2. Advanced Calculation (고급 계산:삼각/지수/로그함수 포함)");
	PrintAt(5, 10, "3. Matrix (행렬 계산)");
	PrintAt(5, 12, "4. Base-N (진수 변환)");
	PrintAt(5, 14, "5. Quit (프로그램 종료)");
}
int Calc_Util::ReadKey(void)
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
		break;
	}
}
int Calc_Util::SelectMode(void)
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
		case SUBMIT:
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
void Calc_Util::Delay(double seconds)
{
	Sleep(1000 * seconds);
}
void Calc_Util::ExitCalc(int xpos, int ypos, double Seconds)
{
	ClearConsole();
	PrintLine(0, 1, CONSOLECOLS);
	PrintLine(0, 18, CONSOLECOLS);

	PrintAt(xpos, ypos, "프로그램이 종료됩니다.");
	Delay(1);
	ClearConsole();
	PrintTitle(Seconds);
}
void Calc_Util::ExitCalc(int xpos, int ypos, double Seconds, string Error)
{
	ClearConsole();
	PrintLine(0, 1, CONSOLECOLS);
	PrintLine(0, 18, CONSOLECOLS);

	PrintAt(xpos, ypos, Error);
	PrintAt(xpos, ypos + 1, "프로그램이 종료됩니다.");
	Delay(1);
	ClearConsole();
	PrintTitle(Seconds);
}

void Calc_Basic::PrintGuide(int xpos, int ypos)
{
	PrintLine(0, 1, CONSOLECOLS);
	PrintLine(0, 18, CONSOLECOLS);
	MoveCursor(xpos, ypos);
	cout <<
		"<식 입력 안내 : 일반 연산 모드>\n"
		"   중위표기법(Infix Notation)으로 작성된 식을 입력하세요.\n"
		"   연산자 생략은 불가능합니다.\n";
}
void Calc_Basic::SetInfixExp(int xpos, int ypos)
{
	MoveCursor(xpos, ypos);
	cout << "계산 식 : ";
	MoveCursor(xpos + 10, ypos);
	cin >> tempExpression;
	InfixExpression = tempExpression;
}
void Calc_Basic::ConvertToPostfix(void)	//if parameter is const string --> Error C2440
{
	string* ptrs = new string;
	*ptrs = InfixExpression;
	string InfixExp = *ptrs;

	string Post_temp;

	string::iterator itr_ind = InfixExp.begin();	//iterator used in index

	vector<char> stack;	//using vector as a stack!

	for (; itr_ind != InfixExp.end(); ++itr_ind)
	{
		//if stream value is not an operator -- pass
		if (operators.find(*itr_ind) == string::npos)
		{
			Post_temp += *itr_ind;
			continue;
		}

		//operator processing
		Post_temp += " ";
		switch (*itr_ind)
		{
		case'(':
			stack.push_back('(');
			break;
		case')':	//starting parenthetical calculation
			while (stack.back() != '(')
			{
				Post_temp += stack.back();
				Post_temp += " ";
				stack.pop_back();
			}
			stack.pop_back();
			break;
		case'+':
		case'-':	//starting add/subtract calculation
			while (stack.size() != 0 && stack.back() != '(')
			{
				Post_temp += stack.back();
				Post_temp += " ";
				stack.pop_back();
			}
			stack.push_back(*itr_ind);
			break;
		case'*':
		case'/':	//starting multiply/divide calculation
			while (stack.size() != 0 && (stack.back() == '*' || stack.back() == '/'))
			{
				Post_temp += stack.back();
				Post_temp += " ";
				stack.pop_back();
			}
			stack.push_back(*itr_ind);
			break;
		case' ':
			break;
		default:
			//unknown error
			cout << "예상치 못한 에러가 발생했습니다. 프로그램을 종료합니다." << endl;
		}
		Post_temp += " ";
	}

	size_t stacksize = stack.size();
	for (size_t i = 0; i < stacksize; ++i)
	{
		Post_temp += " ";
		Post_temp += stack.back();
		stack.pop_back();
	}

	*ptrs = Post_temp;
	PostfixExpression = *ptrs;
	delete ptrs;
}
void Calc_Basic::Calculate(void)
{
	string* ptrs = new string;
	*ptrs = PostfixExpression;
	string PostfixExp;
	PostfixExp = *ptrs;

	vector<double> stack;
	string str = "";
	stringstream temp(PostfixExp);

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
	result = stack.back();
}
void Calc_Basic::PrintResult(int xpos, int ypos)
{
	PrintAt(xpos, ypos, "계산 결과 : ");
	PrintAt(xpos + 12, ypos, result);
}


Calc_Matrix::Calc_Matrix()
{
	//int* rows = new int;
	//int* cols = new int;
	//double* Matrix_A = new double;
	//double* Matrix_B = new double;
}
Calc_Matrix::~Calc_Matrix()
{
	//delete Matrix_A;
	//delete Matrix_B;
}
void Calc_Matrix::DefineMatrix(void)
{
	PrintAt(5, 5, "A,B중 정의할 행렬을 키보드로 입력해 주세요.");
	int selected = ReadKey();
	if (selected == A)
	{
		ClearConsole();
		int rows_temp, cols_temp;
		PrintAt(5, 5, "행 수를 선택하세요.(1~3)");
		cin >> rows_temp;
		PrintAt(5, 8, "열 수를 선택하세요.(1~3)");
		cin >> cols_temp;

		ClearConsole();
		double** Matrix_A = new double*[cols_temp];	//dynamically allocate 2d array
		for (int i = 0; i < cols_temp; i++)
		{
			Matrix_A[i] = new double[rows_temp];
			memset(Matrix_A[i], 0, sizeof(double)*rows_temp);	//initialize memory space to 0
		}

		PrintAt(5, 5, "각 성분들을 입력하세요. 비워둘 수 없습니다.");
		for (int j = 0; j < cols_temp; j++)
		{
			for (int k = 0; k < rows_temp; k++)
			{
				cin >> Matrix_A[j][k];
			}
		}
		ClearConsole();
		PrintAt(5, 5, "입력한 행렬은 다음과 같습니다.");
		for (int j = 0; j < cols_temp; j++)
		{
			for (int k = 0; k < rows_temp; k++)
			{
				cout << Matrix_A[j][k] << " ";
			}
			cout << endl;
		}
		Delay(5);
		ClearConsole();
	}
	else if (selected == B)
	{

	}
}
void Calc_Matrix::EditMatrix(void)
{

}
void Calc_Matrix::GetMatrix(void)
{

}
void Calc_Matrix::Calculate(void)
{

}
