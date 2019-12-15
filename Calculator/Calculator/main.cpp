#include "calculator.h"

int main(void)
{
	Calc_Util* ptc_u = new Calc_Util;
	Calc_Basic* ptc_b = new Calc_Basic;
	Calc_Matrix* ptc_m = new Calc_Matrix;

	Initialize();
	ptc_u->PrintTitle(3);

	while (1)
	{
		ptc_u->PrintMode();
		int mode = ptc_u->SelectMode();
		switch (mode)
		{
		case BASICCALC:
			ptc_b->PrintGuide(18, 2);
			ptc_b->SetInfixExp(3, 6);
			ptc_b->ConvertToPostfix();
			ptc_b->Calculate();
			ptc_b->PrintResult(3, 10);
			ptc_b->Delay(1.2);
			break;
		case ADVANCEDCALC:
			break;
		case BASE_N:
			break;
		case MATRIX:
			ptc_m->PrintGuide(18, 2);
			ptc_m->PrintMode();
			if (ptc_m->SelectMode() == DEFINEMATRIX)
			{
				ptc_m->PrintAt(5, 5, "A, B 중 정의할 행렬을 키보드로 입력해 주세요.");
				if (ptc_m->ReadKey() == A)
					Calc_Matrix* Matrix_A = new Calc_Matrix;
				else if (ptc_m->ReadKey() == B)
					Calc_Matrix* Matrix_B = new Calc_Matrix;
			}
			else if (ptc_m->SelectMode() == EDITMATRIX)
			{

			}
			else if (ptc_m->SelectMode() == CALCULATEMATRIX)
			{

			}
			break;
		case QUIT:
			ptc_u->ExitCalc(5, 5, 1.4);
			return 0;
		default:
			break;
		}
		ptc_u->ClearConsole();
	}
	//Unknown error -- in normal input, cannot reach this point
	ptc_u->ExitCalc(5, 5, 1.4, "에러 : 도달할 수 없는 main() 함수의 끝에 도달했습니다.");
	return 0;
}