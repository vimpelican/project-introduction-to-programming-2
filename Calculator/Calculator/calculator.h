#ifndef CALCULATOR
#define CALCULATOR
#define _USE_MATH_DEFINES		//to use M_PI(exact pi value)
#define CONSOLECOLS 60			//콘솔 창의 가로 길이
#define COMSOLEROWS 20			//콘솔 창의 세로 길이

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77	//define ASCII code for arrow key
#define SUBMIT 13		//define ASCII code for enter key(\r) -- use enter key to submit
#define ESC 27			//define ASCII code for ESC key -- use ESC key to cancle
#define AC '#';
#define A 65
#define B 66

#define BASICCALC 1
#define ADVANCEDCALC 2
#define MATRIX 3
#define BASE_N 4
#define QUIT 0			//define each mode in integer type
#define RETURN 100		//return value to return to mode select screen

#define DEFINEMATRIX 1000
#define EDITMATRIX 1001
#define CALCULATEMATRIX 1002

#include <iostream>
#include <Windows.h>
#include <conio.h>	//for using _getch()
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>

/*
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::stack;
using std::stringstream;
using std::ios_base::eof();
*/

using namespace std;

class Calc {
private:
protected:
public:
	//추상적인 계산기 클래스
};

class Calc_Util : public Calc {
private:
protected:
public:
	void ClearConsole(void);
	void RefreshConsole(void);	//ClearConsole + PrintLine
	void PrintTitle(double seconds);
	void PrintGuide(int xpos, int ypos);
	void PrintAt(int xpos, int ypos, string contents);
	void PrintAt(int xpos, int ypos, double db);
	void PrintLine(int xpos, int ypos, int amount);
	void PrintMode(void);
	int ReadKey(void);
	int SelectMode(void);
	void Delay(double seconds);
	void ExitCalc(int xpos, int ypos, double seconds);
	void ExitCalc(int xpos, int ypos, double seconds, string Error);
	//화면 입출력을 관리하지만 직접적인 계산은 하지 않는 클래스
};

class Calc_Basic : public Calc_Util {
private:
protected:
	string InfixExpression;
	string PostfixExpression;
	string tempExpression;			//string to save infix expression temporarily -- to divide GetInfixExp() and SetInfixExp()
	const string operators = "(+-*/)";		//available opeartors -- parenthes, plus, minus, multiple, divide
	double result;
public:

	void PrintGuide(int xpos, int ypos);
	double GetResult(void) const { return result; };
	void SetInfixExp(int xpos, int ypos);
	void ConvertToPostfix(void);
	void Calculate(void);
	void PrintResult(int xpos, int ypos);
	//기본적인 계산을 수행하는 클래스
};

class Calc_Advanced : public Calc_Basic {
private:
protected:
	const float PI = M_PI;
	const float E = M_E;
public:
	
	/*
	1. 삼각함수, 쌍곡선함수, 역삼각함수의 기본 연산
	2. 지수, 로그, 제곱근 계산
	3. 자주 쓰이는 상수(e, pi 등) 바로 계산 식에 포함 가능
	*/
};

class Calc_Matrix : public Calc_Advanced {
private:
protected:
	int rows;	//행의 수
	int cols;	//열의 수

public:
	Calc_Matrix() : rows(0), cols(0) {};
	Calc_Matrix(int row, int col);
	Calc_Matrix(const Calc_Matrix& Calc_Mat);
	~Calc_Matrix();

	void PrintGuide(int xpos, int ypos);
	void PrintMode(void);
	int SelectMode(void);

	void SetRow(int row);
	void SetCol(int col);
	void DefineMatrix(void);
	void EditMatrix(void);
	void ShowMatrix(void);
	void GetMatrix(void);
	void Calculate(void);
	//double operator+();
	//double operator-();
	//double operator*();
	//행렬 연산을 수행하는 클래스
};

void Initialize(void);
void MoveCursor(int x, int y);

#endif