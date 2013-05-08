#include <stdio.h>

int main()
{
	int sz, p, k, dif, x, y;
	while(scanf("%d %d", &sz, &p) && sz != 0)
	{
		k = 1;
		while(k*k < p)
			k+=2;
		dif = k*k - p;
		if(dif < k)
		{
			x = (k+1)/2;
			y = (k+1)/2 - dif;
		}
		else if(dif < 2*k-1)
		{
			x = (k+1)/2 - (dif-(k-1));	
			y = (k+1)/2 - (k-1);
		}
		else if(dif < 3*k-2)
		{
			x = (k+1)/2 - (k-1);
			y = (k+1)/2 - (k-1) + (dif - 2*(k-1));
		}
		else
		{
			x = (k+1)/2 - (k-1) + (dif - 3*(k-1));
			y = (k+1)/2;
		}
		printf("Line = %d, column = %d.\n", y+(sz-1)/2, x+(sz-1)/2);
	}
	return 0;
}


