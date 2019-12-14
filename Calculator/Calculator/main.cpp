#include "calculator.h"


int main(void)
{
	Calc* ptc;
	Calc_basic* ptc_b = new Calc_basic;

	Initialize();
	PrintTitle(1.2);
	PrintMode();

	while (1)
	{
		int i = SelectMode();
		switch (i)
		{
		case BASICCALC:
		{
			ptc_b->ClearConsole();
			ptc_b->GetSetInfixExp();
			ptc_b->ConvertToPostfix();	//null pointer error, why?
			ptc_b->Calculate();
			cout << ptc_b->GetPostfix() << endl;
			cout << ptc_b->GetResult() << endl;

			Sleep(1000000);
		}
			break;
		case ADVANCEDCALC:
			break;
		case BASE_N:
			break;
		case MATRIX:
			break;
		case QUIT:
			return 0;
		default:
			break;
		}
		system("cls");
	}
	getchar();
	return 0;
}