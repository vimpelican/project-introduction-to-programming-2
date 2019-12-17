#include "matrix.h"

Matrix::Matrix()
{
	rows = cols = NULL;
	pptd = NULL;
}
Matrix::Matrix(int r, int c)
{
	rows = r;
	cols = c;

	for (int i = 0; i < cols; i++)
	{
		pptd[i] = new double[rows];
		memset(pptd[i], 0, sizeof(double)*(cols));	//initialize memory space to 0
	}
}
Matrix::~Matrix()
{

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

/*
Matrix Matrix::operator+(Matrix& other)
{
	Matrix
	double** pptd_temp;
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			pptd_temp[r][c] = pptd[r][c] + (other.GetPointer)[r][c];	//add each element
		}
	}
	return pptd_temp;
}
Matrix Matrix::operator*(Matrix& other)
{
	double** pptd_temp;
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			pptd_temp[r][c] = pptd[r][c] * (other.GetPointer)[r][c];	//multiple each element
		}
	}
}
*/