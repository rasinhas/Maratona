#include <stdio.h>

int main()
{
	float a, g, Ra, Rg;
	scanf("%f%f%f%f", &a, &g, &Ra, &Rg);
	if(Ra/a > Rg/g)
		printf("A\n");
	else
		printf("G\n");
	return 0;
} 



