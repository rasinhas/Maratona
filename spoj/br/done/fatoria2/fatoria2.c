#include <stdio.h>

int main()
{
	int a=1, x, i;
	scanf("%d", &x);
	for(i=1;i<=x;i++)
		a *= i;
	printf("%d\n", a);
	return 0;
}


