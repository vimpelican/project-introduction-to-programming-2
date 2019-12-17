#include "matrix.h"

Matrix::Matrix()
{
	rows = 0;
	cols = 0;
	pptd = NULL;
}
Matrix::Matrix(int row, int col)
{
	rows = row;
	cols = col;
	pptd = new double*[rows];
	for (int i = 0; i < rows; i++)
		pptd[i] = new double[cols];
}
Matrix::~Matrix()
{
	for (int i = 0; i < rows; i++)
		delete[] pptd[i];
	delete[] pptd;
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
		for (int r = 0; r < rows; r++)
		{
			for (int c = 0; c < cols; c++)
			{
				MoveCursor(8+r, 8+c);
				cout << (scarlar) * (pptd[r][c]);
			}
			cout << endl;
		}
	}
	else if (mode == "TRANSPOSE")
	{
		for (int r = 0; r < rows; r++)
		{
			for (int c = 0; c < cols; c++)
			{
				MoveCursor(8 + r, 8 + c);
				cout <<  pptd[c][r] << " ";	//change rows and cols
			}
			cout << endl;
		}
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