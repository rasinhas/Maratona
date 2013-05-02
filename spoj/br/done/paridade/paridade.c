#include <stdio.h>

int main()
{
	int n, x, p, i, k, bin[32];
	while(n != 0)
	{
		i = 0;
		p = 0;
		scanf("%d", &n);
		if(n == 0)
			return 0;
		x = n;
		printf("The parity of ");
		while(x > 0)
		{
			bin[i]=x%2;
			p += x%2;
			x /= 2;
			i++;
		}
		for(k=i-1;k>=0;k--)
		{
			printf("%d",bin[k]);
		}
		printf(" is %d (mod 2).\n", p);
	}
	return 0;
}

