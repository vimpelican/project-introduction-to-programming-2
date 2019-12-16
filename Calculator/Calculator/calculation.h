#include "calculator.h"

class Calculation : public Calculator
{
private:
	string InfixExpression;
	string PostfixExpression;
	const string operators = "(+-*/)";		//available opeartor string set
	double result;
public:
	Calculation() : result(0.0) {};
	void SetInfixExpression(void);
	void ConvertExpression(void);
	void Calculate(void);
};