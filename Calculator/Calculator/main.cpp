#include "calculator.h"

int main(void)
{
	Initialize();
	PrintTitle(1.2);
	PrintMode();
	while (1)
	{
		switch (SelectMode())
		{
		case BASICCALC:
			break;
		case ADVANCEDCALC:
			break;
		case BASE_N:
			break;
		case MATRIX:
			break;
		case QUIT:
			break;
		default:
			break;
		}
		system("cls");
	}

	getchar();
	return 0;
}
