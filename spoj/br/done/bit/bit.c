#include <stdio.h>

int main()
{
	int n, i=1, val;
	while(1)
	{
		scanf("%d", &n);
		if(n == 0)
			return 0;
		printf("Teste %d\n", i);
		val = n / 50;
		n -= val * 50;
		printf("%d ", val);
		val = n / 10;
		n -= val * 10;
		printf("%d ", val);
		val = n / 5; 
		n -= val * 5;   
		printf("%d ", val);
		val = n; 
		printf("%d\n\n", val);
		i++;
	}
	return 0;
}

