#include "calculator.h"

class Arithmetic : public Calculator
{
private:
	string InfixExpression;
	string PostfixExpression;
	const string operators = "(+-*/)";		//available opeartors(arithmetic) string set
	double result;
public:
	Arithmetic() : result(0.0) {};
	void SetInfixExpression(void);	//read user input(in infix notation) and save to InfixExpression
	void ConvertExpression(void);	//convert infix notation to postifx notation and save to PostfixExpression
	void Calculate(void);			//calculate result
	double GetResult(void) { return result; }
};