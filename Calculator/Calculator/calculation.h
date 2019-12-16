#include "calculator.h"

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
