#include "base_n.h"


void ChangeDecimal(int binary)  // 2진수를 10진수로 바꿔주는 함수
{
	int sum = 0;
	int temp = 1;
	while (binary != 0)
	{
		if (binary % 10 != 0 && binary % 10 != 1)
		{
			printf("잘못입력했습니다");
			return;
		}

		if (binary % 10 != 0)
		{
			sum = sum + temp;
		}
		binary = binary / 10;
		temp = temp * 2;
	}
	printf("Answer is %d\n", sum);

}

void ChangeBinary(int decimal)  // 10진수를 2진수로 바꿔주는 함수
{
	int i = 99; char c[17] = "0123456789ABCDEF", result[100];

	result[i] = '\0'; // i=99 
	while (decimal != 0) {
		result[--i] = c[decimal % 2]; // result[] <-- 나머지 
		decimal /= 2; // 몫 
	}
	printf("Answer is %s\n", &result[i]);

}

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