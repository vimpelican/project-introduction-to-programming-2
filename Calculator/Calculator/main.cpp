#include "calculator.h"

int main(void)
{
	Initialize();
	ShowTitle(1);
	ShowMode();
	while (1)
	{
		switch (SelectMode())
		{
		case CALCULATE:
			break;
		case TRIGONOMETRIC:
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
