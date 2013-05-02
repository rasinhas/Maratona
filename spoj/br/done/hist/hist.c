#include <stdio.h>
int main()
{
	int n;
	int P[1001], i, j, existe, total;
	while(1)
	{
		scanf("%d", &n);
		if(!n)
			return 0;
		total = 0;
		for(i=0;i<n;i++)
		{
			scanf("%d", &P[i]);
			existe = 0;
			if(i != 0)
			{
				for(j=1;j<=i;j++)
				{
					if(P[i-j] == P[i])
					{
						total += j;
						existe = 1;
						break;
					}
				}
			}
			if(existe == 0)
			{
				total += P[i] + i;
			}
		}
		printf("%d\n", total);
	}
}


