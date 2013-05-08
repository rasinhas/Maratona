#include <stdio.h>

int main()
{
	int X1, Y1, X2, Y2;
	while(1)
	{
		scanf("%d %d %d %d", &X1, &Y1, &X2, &Y2);
		if(X1 == 0)
			return 0;
		if(X1 == X2 && Y1 == Y2)
			printf("0\n");
		else if(X1 == X2 || Y1 == Y2)
			printf("1\n");
		else if((X1-X2) == (Y1-Y2) || (X1-X2) == -(Y1-Y2))
			printf("1\n");
		else
			printf("2\n");
	}
}

