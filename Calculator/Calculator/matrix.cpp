#include "matrix.h"

Matrix::Matrix(int r, int c)
{
	rows = r;
	cols = c;
	pptd = NULL;	//to check whether matrix is exists or not
}
void Matrix::DefineMatrix(void)
{
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			cin >> pptd[r][c];
		}
	}
}
void Matrix::Calculate(string mode)
{
	if (pptd == NULL)
		isDefined = false;
	else
		isDefined = true;

	if (mode == "ADDMATRIX")
	{

	}
	else if (mode == "SCALARPRODUCT")
	{

	}
	else if (mode == "TRANSPOSE")
	{

	}
	else if (mode == "MATRIXPRODUCT")
	{

	}
	else if (mode == "INVERSE")
	{

	}
}
Matrix Matrix::operator+(Matrix& other)
{

}
Matrix Matrix::operator*(Matrix& other)
{

}