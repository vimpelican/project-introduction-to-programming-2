#include "calculator.h"

class Arithmetic : public Calculator
{
private:
	string InfixExpression;
	string PostfixExpression;
	const string operators = "(+-*/)";		//available opeartors(arithmetic) string set
	double result;
public:
	Arithmetic() : result(0.0), InfixExpression(" "), PostfixExpression("") {};
	void SetInfixExpression(void);
	void ConvertExpression(void);
	void Calculate(void);
};