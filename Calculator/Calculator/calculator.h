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

#define CALCULATION 1
#define MATRIX 2
#define BASE_N 3
#define QUIT 4			//define each mode in integer type
#define RETURN 100		//return value to return to mode select screen

#define DEFINEMATRIX 1000
#define EDITMATRIX 1001
#define CALCULATEMATRIX 1002

#include <iostream>
#include <Windows.h>	//to control console & handle cursor
#include <conio.h>		//to use _getch()
#include <cstdlib>
#include <ctime>		//to use srand((unsigned int)time(NULL));
#include <cmath>		//to use math features
#include <string>		//to use C++ style string
#include <vector>		//to use std::vector
#include <stack>		//to use std::stack(not sure)
#include <utility>		//to use pair<int, int>
#include <sstream>		//to use stringstream;

//try not to use using namespace std;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::pair;
using std::vector;
using std::stack;
using std::stringstream;

class Calculator
{
private:
protected:
public:
	virtual void PrintGuide(double seconds);
	virtual void PrintMode(void);
	virtual int SelectMode(void);		//declared in virtual to use in Utility, Matrix, probably Base_N too
	virtual void Calculate(void);
};
void Initialize(void);
void MoveCursor(int xpos, int ypos);
#endif