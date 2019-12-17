#include "calculator.h"

class Arithmetic : public Calculator
{
private:
	string InfixExpression;
	string PostfixExpression;
	const string operators = "(+-*/)";		//available opeartors(arithmetic) string set
	double result;
	stack<char> s2;				//stack which holds opeartors
	stack<double> s1;	//stack which holds values to calculate result
	char buffer[100];				//work as a buffer(temporary value)
public:
	Arithmetic();
	void SetInfixExpression(void);	//read user input(in infix notation) and save to InfixExpression
	void ConvertExpression(void);	//convert infix notation to postifx notation and save to PostfixExpression
	void Calculate(void);			//calculate result
	double GetResult(void) { return result; }
	int OperatorPriority(char _operator);	//define operator priority
};