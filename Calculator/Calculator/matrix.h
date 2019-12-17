#include "calculator.h"

class Matrix : public Calculator
{
private:
	int rows;
	int cols;
	double** pptd;		//pointer to pointer to double type -- to allocate 2d array dynamically
public:
	Matrix();
	Matrix(int row, int col);
	Matrix(const Matrix&);
	~Matrix();
	void DefineMatrix(void);
	//void EditMatrix(void);
	void Calculate(string mode);
	double** GetPointer(void) { return pptd; };
	//Matrix operator+(Matrix& other);
	//Matrix operator*(Matrix& other);
};