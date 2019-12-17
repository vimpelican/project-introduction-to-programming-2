#include "arithmetic.h"
#include "utility.h"
#include "matrix.h"
#include "base_n.h"

int main(void)
{
	Initialize();
	Utility* UTL = new Utility();
	Arithmetic* ARI = NULL;
	Matrix* Matrix_A = NULL;
	Matrix* Matrix_B = NULL;
	Base_N* BN = NULL;

	UTL->PrintTitle();
	UTL->WaitforSec(1.5);

	while (1)
	{
		UTL->RefreshConsole();
		UTL->SetPos(5, 1);
		UTL->PrintGuide("BASIC");
		UTL->SetPos(5, 5);
		UTL->PrintModes("BASIC");
		switch (UTL->SelectMode("BASIC"))
		{
			UTL->RefreshConsole();
		case ARITHMETIC:
			ARI = new Arithmetic();
			UTL->SetPos(5, 1);
			UTL->PrintGuide("ARITHMETIC");
			ARI->SetInfixExpression();
			ARI->ConvertExpression();
			ARI->Calculate();
			UTL->RefreshConsole();
			UTL->SetPos(12, 10);
			UTL->PrintConsole(ARI->GetResult());
			UTL->WaitforSec(3);
			break;
		case MATRIX:
			UTL->SetPos(5, 1);
			UTL->PrintGuide("MATRIX");
			UTL->SetPos(5, 5);
			UTL->PrintModes("MATRIX");
			switch (UTL->SelectMode("MATRIX"))
			{
			case DEFINEMATRIX:
				UTL->SetPos(5, 1);
				UTL->PrintGuide("DEFINEMATRIX");
				break;
			case CALCULATEMATRIX:
				UTL->SetPos(5, 1);
				UTL->PrintGuide("CALCULATEMATRIX");
				break;
			}
			break;
		case BASE_N:
			break;
		case QUIT:
			UTL->ExitCalc();
			return 0;
		default:
			break;
		}
	}
	//Unknown error -- in normal input, cannot reach this point
	//ptc_u->ExitCalc(5, 5, 1.4, "에러 : 도달할 수 없는 main() 함수의 끝에 도달했습니다.");
	return 0;
}