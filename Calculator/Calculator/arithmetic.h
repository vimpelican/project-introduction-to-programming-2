#include "calculator.h"

class Arithmetic : public Calculator
{
private:
	string InfixExpression;
	string PostfixExpression;
	const string operators = "(+-*/)";		//available opeartors(arithmetic) string set
	double result;
	stack<char> stack_operator;		//stack which holds opeartors
	stack<double> stack_value;		//stack which holds values to calculate result
	stack<int> stack_temp;			//stack which holds temporary value(which have to be calulated)
public:
	Arithmetic();
	void SetInfixExpression(void);	//read user input(in infix notation) and save to InfixExpression
	void ConvertExpression(void);	//convert infix notation to postifx notation and save to PostfixExpression
	void Calculate(void);			//calculate result
	double GetResult(void) { return result; }
	int OperatorPriority(char _operator);	//define operator priority
};