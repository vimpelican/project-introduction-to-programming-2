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
		{
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
		}
		case MATRIX:
		{
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
				UTL->PrintModes("SELECTMATRIX");
				if (UTL->SelectMode("SELECTMATRIX") == A)
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
				else  //unknown error, delete else if(UTL->SelectMode()...). using else -- w
				{
					int r_temp, c_temp;
					UTL->RefreshConsole();
					UTL->SetPos(5, 1);
					UTL->PrintGuide("DEFINEMATRIX_B");
					UTL->SetPos(33, 7);
					cin >> r_temp;
					UTL->SetPos(33, 9);
					cin >> c_temp;
					UTL->SetPos(5, 15);
					Matrix_B = new Matrix(r_temp, c_temp);
					Matrix_B->DefineMatrix();
				}
				UTL->SetPos(5, 17);
				UTL->PrintConsole("성공적으로 행렬을 정의했습니다. 초기 화면으로 돌아갑니다.");
				//not yet implemented exceptional input
				UTL->WaitforSec(2);
				break;
			case CALCULATEMATRIX:
				UTL->RefreshConsole();
				UTL->SetPos(3, 1);
				UTL->PrintGuide("CALCULATEMATRIX");
				UTL->SetPos(5, 9);
				UTL->PrintModes("CALCULATEMATRIX");
				switch (UTL->SelectMode("CALCULATEMATRIX"))
				{
				case ADDMATRIX:
					UTL->RefreshConsole();
					break;
				case SCALAPRODUCT:
					UTL->RefreshConsole();
					UTL->SetPos(5, 9);
					UTL->PrintModes("SELECTMATRIX");
					if (UTL->SelectMode("SELECTMATRIX") == A)
					{
						UTL->RefreshConsole();
						UTL->SetPos(5, 5);
						UTL->PrintConsole("스칼라 값을 입력해 주세요.");
						int scarlar;
						cin >> scarlar;
						Matrix_A->setScarlar(scarlar);
						UTL->SetPos(8, 8);
						Matrix_A->Calculate("SCALARPRODUCT");
						UTL->WaitforSec(3);
					}
					else if (UTL->SelectMode("SELECTMATRIX") == B)
					{
						UTL->RefreshConsole();
						UTL->SetPos(5, 5);
						UTL->PrintConsole("스칼라 값을 입력해 주세요.");
						int scarlar;
						cin >> scarlar;
						Matrix_B->setScarlar(scarlar);
						UTL->SetPos(8, 8);
						Matrix_B->Calculate("SCALARPRODUCT");
						UTL->WaitforSec(3);
					}
					break;
				case TRANSPOSE:
					UTL->RefreshConsole();
					UTL->SetPos(5, 9);
					UTL->PrintModes("SELECTMATRIX");
					if (UTL->SelectMode("SELECTMATRIX") == A)
					{
						UTL->SetPos(8, 8);
						Matrix_A->Calculate("TRANSPOSE");
						UTL->WaitforSec(3);
					}
					else if (UTL->SelectMode("SELECTMATRIX") == B)
					{
						UTL->SetPos(8, 8);
						Matrix_B->Calculate("TRANSPOSE");
						UTL->WaitforSec(3);
					}
					break;
				case MATRIXPRODUCT:
					UTL->RefreshConsole();
					break;
				case INVERSE:
					UTL->RefreshConsole();
					break;
				}
				break;
				break;
			}
		}
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
	//ExitCalc(5, 5, 1.4, "에러 : 도달할 수 없는 main() 함수의 끝에 도달했습니다.");
	return 0;
}