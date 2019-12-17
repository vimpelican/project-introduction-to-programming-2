#include "calculator.h"

class Matrix : public Calculator
{
private:
	int rows;
	int cols;
	double** pptd;		//pointer to pointer to double type -- to allocate 2d array dynamically
public:
	Matrix();
	Matrix(int rows, int cols);
	Matrix(const Matrix&);
	~Matrix();
	void DefineMatrix(void);
	//void EditMatrix(void);
	void Calculate(string mode);
	double** GetPointer(void) { return pptd; };
	//Matrix operator+(Matrix& other);
	//Matrix operator*(Matrix& other);
};
/*ptc_m->PrintGuide(18, 2);
ptc_m->PrintModes();
if (ptc_m->SelectMode() == DEFINEMATRIX
{
ptc_m->PrintAt(5, 5, "A, B 중 정의할 행렬을 키보드로 입력해 주세요.");
if (ptc_m->ReadKey() == A)
{
	ptc_u->RefreshConsole();
	int r_temp, c_temp;
	ptc_m->PrintAt(5, 5, "행 수를 선택하세요.(1~3)");
	cin >> r_temp;
	ptc_m->PrintAt(5, 6, "열 수를 선택하세요.(1~3)");
	cin >> c_temp;
	Matrix_A = new Matrix(r_temp, c_temp);
	ptc_u->RefreshConsole();
	ptc_m->PrintAt(5, 6, "각 성분들을 입력하세요. 비워둘 수 없습니다.");
	for (int r = 0; r < Matrix_A->GetRow(); r++)
	{
		for (int c = 0; c < Matrix_A->GetCol(); c++)
		{
			MoveCursor(5, 7);
			cin >> Matrix_A->GetP()[r][c];
		}
	}
}
else if (ptc_m->ReadKey() == B)
{

}
}
else if (ptc_m->SelectMode() == EDITMATRIX)
{
	ptc_m->RefreshConsole();
	ptc_m->PrintAt(5, 5, "A, B 중 수정할 행렬을 키보드로 입력해 주세요.");
}
else//왜 엔터를 두번 눌러야 여기로 들어가지?
{
	ptc_m->RefreshConsole();
	for (int r = 0; r < Matrix_A->GetRow(); r++)
	{
		for (int c = 0; c < Matrix_A->GetCol(); c++)
		{
			ptc_m->PrintAt(5, 10, "TEST");
			MoveCursor(5 + r, 6 + c);
			cout <<  Matrix_A->GetP()[r][c];
		}
		cout << endl;
	}
	ptc_u->Delay(2);
}*/