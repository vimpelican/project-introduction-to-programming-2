#include "calculator.h"


int main(void)
{
	Calc* ptc;
	Calc_basic* ptc_b = 0;
	Calc_Eng* ptc_e;
	string str;

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
			system("cls");
			ptc_b->ClearConsole();
			str = ptc_b->InputInfixExp();
			ptc_b->ConvertToPostfix(str);
			ptc_b->Calculate(str);
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