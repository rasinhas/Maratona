#include <stdio.h>
#include <stdlib.h>
#define FOR(i,n) for(i=0;i<n;i++)

int main()
{
	int i, j;
	int A, C, h1, h0, cont;
	while(1)
	{
		scanf("%d %d", &A, &C);
		if(A == 0)
			return 0;
		cont = 0;
		scanf("%d", &h0);
		cont += A - h0;
		for(i=1;i<C;i++)
		{
			scanf("%d", &h1);
			if(h0 > h1)
				cont += h0 - h1;
			h0 = h1;
		}
		printf("%d\n", cont);
	}
}



