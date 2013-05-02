#include <stdio.h>

int main()
{
	int n, C, V, R, i;
	while(1)
	{
		scanf("%d", &n);
		R=0;
		if(n == 0)
			return 0;
		for(i=0;i<n;i++)
		{
			scanf("%d%d", &C, &V);
			R+=V/2;
		}
		printf("%d\n", R/2);
	}
	return 0;
}

