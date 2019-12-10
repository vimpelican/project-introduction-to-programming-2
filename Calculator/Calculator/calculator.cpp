#include "calculator.h"

using namespace std;

void SetCalc(void)
{
	system("mode con cols = 50 lines = 20 | title Calculator");
	cout << "이 프로그램은 가장 기본적인 계산기와 공학용 계산 기능, 고급 공학용 계산 기능을 수행합니다." << endl;
	cout <<
		"모드를 선택해 주세요"
		"1. 가장 기본적인 계산"
		"2. 기본적인 공학용 계산"
		"3. 고급 공학용 계산";

}