#ifndef CALCULATOR
#define CALCULATOR
#define CONSOLECOLS 70
#define CONSOLEROWS 30

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
	virtual void PrintGuide(double seconds) = 0;
	virtual void PrintMode(void);
	virtual int SelectMode(void);		//declared in virtual to use in Utility, Matrix, probably Base_N too
	virtual void Calculate(void);
};

class Utility : public Calculator
{
private:
	double result;
public:
	//only Utility method
	void RefreshConsole(void);			//erase everything in console and print two lines(basic UI)
	void WaitforSec(double seconds);	//wait console in seconds
	void PrintTitle(double seconds);	//print title "CALCULATOR"
	int InstantReadKey(void);			//read keyboard input without buffer(instantly input value)
	template <typename contents> void PrintAt(int xpos, int ypos, contents);
	
	virtual void PrintGuide(int xpos, int ypos);	//basic guide : explain program
	virtual void PrintMode(void);	//basic mode : calculation || matrix || Base_N
	void ExitCalc(void);			//show "terminated" string and terminate whole program
};

class Calculation : public Calculator
{
private:
	string InfixExpression;
	string PostfixExpression;
	const string operators = "(+-*/)";		//available opeartor string set
	double result;
public:
	virtual void PrintGuide(void);
	void SetInfixExpression(void);
	void ConvertExpression(void);
	void PrintResult(void);
};

class Matrix : public Calculator
{
private:
	int rows;
	int cols;
	double** pptd;		//pointer to pointer to double type -- to allocate 2d array dynamically
public:
	void PrintGuide(void);
	virtual int SelectMode(void);
	void DefineMatrix(void);
	void EditMatrix(void);
	void Calculate(void);
	double** GetPointer(void);
};

class Base_N : public Calculator
{
private:
public:

};

void Initialize(void);
void MoveCursor(int xpos, int ypos);
#endif