#include "calculator.h"

int main(void)
{
	Calc* ptc;
	Calc_basic* ptc_b = new Calc_basic;

	Initialize();
	PrintTitle(1.2);

	while (1)
	{
		PrintMode();
		int mode = SelectMode();
		switch (mode)
		{
		case BASICCALC:
		{
			ptc_b->ClearConsole();
			ptc_b->PrintGuide(22, 2);
			ptc_b->SetInfixExp(3, 6);
			ptc_b->ConvertToPostfix();	//null pointer error, why?
			ptc_b->Calculate();
			ptc_b->PrintResult(3, 10);
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
			ExitCalc(5, 5, 1.2);
			return 0;
		default:
			break;
		}
		ptc_b->ClearConsole();
	}
	//Unknown error -- in normal input, cannot reach this point
	ExitCalc(5, 5, 1.2, "도달할 수 없는 main() 함수의 끝에 도달했습니다.");
	return 0;
}