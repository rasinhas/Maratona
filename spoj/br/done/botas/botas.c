#include <stdio.h>

int main()
{
	int par, n, m, botas[50], i;
	char l;
	while(scanf("%d", &n) != EOF)
	{
		for(i=0;i<50;i++) botas[i]=0;
		par=0;
		for(i=0;i<n;i++)
		{
			scanf("%d %c", &m, &l);
			if((botas[m-30]<0 && l =='D')||(botas[m-30]>0 && l =='E')) par++;
			if(l == 'D') botas[m-30]++;
			else botas[m-30]--;
		}
		printf("%d\n",par);
	}
	return 0;
}
