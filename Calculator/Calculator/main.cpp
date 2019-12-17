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
		UTL->SetPos(5, 9);
		UTL->PrintModes("BASIC");
		switch (UTL->SelectMode("BASIC"))
		{
			UTL->SetPos(5, 5);
			UTL->PrintModes("BASIC");
		case ARITHMETIC:
			UTL->RefreshConsole();
			ARI = new Arithmetic();
			UTL->SetPos(6, 1);
			UTL->PrintGuide("ARITHMETIC");
			UTL->SetPos(17, 16);
			ARI->SetInfixExpression();
			ARI->ConvertExpression();
			ARI->Calculate();
			UTL->SetPos(17, 20);
			UTL->PrintConsole(ARI->GetResult());
			UTL->WaitforSec(3);
			break;
		case MATRIX:
			UTL->RefreshConsole();
			UTL->SetPos(5, 1);
			UTL->PrintGuide("MATRIX");
			UTL->SetPos(5, 9);
			UTL->PrintModes("MATRIX");
			switch (UTL->SelectMode("MATRIX"))
			{
			case DEFINEMATRIX:
				UTL->RefreshConsole();
				UTL->SetPos(5, 1);
				UTL->PrintGuide("DEFINEMATRIX");
				UTL->SetPos(5, 9);
				UTL->PrintModes("DEFINEMATRIX");
				if (UTL->SelectMode("DEFINEMATRIX") == A)
				{
					int r_temp, c_temp;
					UTL->RefreshConsole();
					UTL->SetPos(5, 1);
					UTL->PrintGuide("DEFINEMATRIX_A");
					UTL->SetPos(33, 7);
					cin >> r_temp;
					UTL->SetPos(33, 9);
					cin >> c_temp;
					UTL->SetPos(5, 15);
					Matrix_A = new Matrix(r_temp, c_temp);
					Matrix_A->DefineMatrix();
				}
				else if (UTL->InstantReadKey() == B)
				{
					UTL->RefreshConsole();
					UTL->SetPos(5, 1);
					UTL->PrintGuide("DEFINEMATRIX_B");
				}
				break;
			case CALCULATEMATRIX:
				UTL->SetPos(5, 1);
				UTL->PrintGuide("CALCULATEMATRIX");
				break;
			}
			break;
		case BASE_N:
			BN = new Base_N;
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