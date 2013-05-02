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
	int i, j, l, n, k, prim, len;
	int cont;
	char seq[200100], resp[200100], ant;
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		scanf("%s %d", seq, &k);
		printf("%s\n", seq);
		for(j=0;j<k;j++)
		{
			len = strlen(seq);
			ant = seq[0];
			prim = 1;
			cont = 0;
			for(l=0;l<len+1;l++)
			{
				if(seq[l] == ant)	
					cont++;
				else if(seq[l] != ant)
				{
					if(prim)
						sprintf(resp,"%d%c", cont, ant);
					else
						sprintf(resp,"%s%d%c", resp, cont, ant);
					cont = 1;
					prim = 0;
				}
				ant = seq[l];
			}
			sprintf(seq,"%s", resp);
			printf("%s\n", seq);
		}
		printf("\n");
	}
	return 0;
}


