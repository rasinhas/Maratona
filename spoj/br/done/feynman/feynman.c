#include <stdio.h>

int main()
{
	int fey[101], i, F;
	fey[0] = 0;
	fey[1] = 1;
	for(i=2;i<101;i++)
	{
		fey[i] = fey[i-1] + i*i;
	}
	while(1)
	{
		scanf("%d", &F);
		if(F == 0)
			return 0;
		printf("%d\n", fey[F]);
	}
}

