#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 0x3f3f3f
#define rep(i,n) for(i=0;i<(n);i++)
#define min(x,y) x < y ? x : y
#define max(x,y) x > y ? x : y
#define INF 0x3f3f3f

int main()
{
	int n;
	int parm, impm, paro, impo, num, aux1, aux2, i;
	while(scanf("%d", &n) && n)
	{
		parm = 0;
		paro = 0;
		impm = 0;
		impo = 0;
		for(i=0;i<n;i++)
		{
			scanf("%d", &num);
			if(num%2 == 0)
				parm++;
			else
				impm++;
		}
		for(i=0;i<n;i++)
		{
			scanf("%d", &num);
			if(num%2 == 0)
				paro++;
			else
				impo++;
		}
		aux1 = min(impm, paro);
		aux2 = min(parm, impo);
		printf("%d\n", n-(aux1+aux2));
	}
	return 0;
}


