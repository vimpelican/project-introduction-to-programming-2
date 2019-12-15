#include "calculator.h"

int main(void)
{
	Calc* ptc;
	Calc_basic* ptc_b = new Calc_basic;

	Initialize();
	PrintTitle(1.2);
	PrintMode();

	while (int i = SelectMode())
	{
		switch (i)
		{
		case BASICCALC:
		{
			ptc_b->ClearConsole();
			ptc_b->PrintGuide(22, 2);
			ptc_b->GetInfixExp();
			ptc_b->SetInfixExp();
			ptc_b->ConvertToPostfix();	//null pointer error, why?
			ptc_b->Calculate();
			cout << ptc_b->GetResult() << endl;
			Sleep(10000);
		}
			break;
		case ADVANCEDCALC:
			break;
		case BASE_N:
			break;
		case MATRIX:
			break;
		case QUIT:
			break;
		default:
			break;
		}
		ptc_b->ClearConsole();
	}
	getchar();
	return 0;
}