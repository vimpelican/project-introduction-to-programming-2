#include "calculator.h"

class Matrix : public Calculator
{
private:
	int rows;
	int cols;
	double** pptd;		//pointer to pointer to double type -- to allocate 2d array dynamically
public:
	virtual int SelectMode(void);
	void DefineMatrix(void);
	void EditMatrix(void);
	void Calculate(void);
	double** GetPointer(void);
};
