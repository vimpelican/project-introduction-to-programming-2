#include "calculator.h"

class Base_N : public Calculator
{
private:

public:
	void ChangeDecimal(int binary) {} //선언
	void ChangeBinary(int decimal) {} // 선언
};

/*
int main()
{
	int numSystem;
	int n, i = 99; char c[17] = "0123456789ABCDEF", result[100];
	cout << "변환할 숫자를 입력하세요: ";
	scanf("%d", &n);
	cout << "변환할 진수 입력(2진수, 10진수): ";
	scanf("%d", &numSystem);
	if (numSystem == 2) {
		ChangeBinary(n);
	}
	else if (numSystem == 10) {
		ChangeDecimal(n);
	}
	numSystem = 0;
};
*/